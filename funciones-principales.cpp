#include <fstream>
#include "definiciones.h"
#include "funciones-principales.h"

using namespace std;


vector<double> cmm (int teams, int matches, ifstream& inputFile) {

    matrix C;
    for (int i = 0; i < teams; i++) {
        C.push_back(vector<double>(teams, 0));
        C[i][i] = 2;
    }


    vector<double> wins(teams, 0);
    vector<double> losses(teams, 0);


    for (int i = 0; i < matches; i++) {
        int date,team1,score,team2,score2;
        inputFile>>date>>team1>>score>>team2>>score2;

        if (score>score2) {
            wins[team1 - 1] += 1;
            losses[team2 - 1] += 1;
        }else{
            wins[team2 - 1] += 1;
            losses[team1 - 1] += 1;
        }

        C[team1 - 1][team2 - 1] -= 1;
        C[team2 - 1][team1 - 1] -= 1;

        C[team1 - 1][team1 - 1] += 1;
        C[team2 - 1][team2 - 1] += 1;
    }
    inputFile.close();

    vector<double> b(teams, 0);
    for(int i = 0; i < teams; i++) {
        b[i] = 1 + (wins[i] - losses[i]) / 2;
    }

    return gauss(C,b);
}


vector<double> wp(int teams, int matches,ifstream& inputFile){
    vector<double> matches_played(teams,0);
    vector<double> wins(teams,0);

    for(int i = 0; i<matches;i++){
        int date,team1,score,team2,score2;
        inputFile>>date>>team1>>score>>team2>>score2;
        if(score>score2){
            wins[team1-1] += 1;
        } else{
            wins[team2-1] +=1;
        }
        matches_played[team1-1] +=1;
        matches_played[team2-1] +=1;
    }
    inputFile.close();

    vector<double> res(teams);
    for(int i=0; i,teams; i++){
        res[i]=wins[i]/matches_played[i];
    }
    return res;
}


/*
vector<double> elo(int teams, int matches, ifstream& inputFile){

    k=20;
    vector<double> matches_played(teams,0);
    vector<double> ratings(teams,1500);        //numero arbitrario de elo rating para arrancar (1500)

    for(int i = 0; i<matches;i++) {
        int date, team1, score1, team2, score2;
        inputFile >> date >> team1 >> score1 >> team2 >> score2;
        Ra = ratings[team1-1];
        Rb = ratings[team2-1];

        if(score1>score2){
            eloRating(Ra,Rb,k,1,0); //el team1 se lleva 1 punto el team2 0
        }else{
            eloRating(Ra,Rb,k,0,1);
        }
        //los ratings ya fueron updateados
        ratings[team1-1] = Ra;
        rating[team2-1] = Rb;

    }
    return ratings;

}
*/
