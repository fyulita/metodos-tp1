#include "funciones-secundarias.cpp"
#include <fstream>
#include <map>
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




vector<double> cmmatp (double teams, double matches, ifstream& inputFile) {

    matrix C;
    for (double i = 0; i < teams; i++) {
        C.push_back(vector<double>(teams, 0));
        C[i][i] = 2;
    }

    vector<double> wins(teams,0);
    vector<double> losses(teams,0);

    map<double,double> players;


    double played = 0;


    for (int i = 0; i < matches; i++) {
        double date,team1,score,team2,score2;
        inputFile >> date >> team1 >> score >> team2 >> score2;

        if(players.count(team1)==0){
            players[team1] = played;
            played++;
        }

        if(players.count(team2)==0){
            players[team2] = played;
            played++;
        }


        if (score>score2) {
            wins[players[team1]] += 1;
            losses[players[team2]] += 1;
        }else{
            wins[players[team2]] += 1;
            losses[players[team1]] += 1;
        }

        C[players[team1]][players[team2]] -= 1;
        C[players[team2]][players[team1]] -= 1;

        C[players[team1]][players[team1]] += 1;
        C[players[team2]][players[team2]] += 1;
    }
    inputFile.close();

    vector<double> b(teams, 0);
    for(double i = 0; i < teams; i++) {
        b[i] = 1 + (wins[i] - losses[i]) / 2;
    }

    return gauss(C,b);
}


vector<double> wp(double teams, double matches,ifstream& inputFile){
    vector<double> matches_played(teams,0);
    vector<double> wins(teams,0);

    map<double,double> players;
    double played=0;

    for(double i = 0; i<matches;i++){
        double date,team1,score,team2,score2;
        inputFile>>date>>team1>>score>>team2>>score2;

        if(players.count(team1)==0){
            players[team1] = played;
            played++;
        }

        if(players.count(team2)==0){
            players[team2] = played;
            played++;
        }

        if(score>score2){
            wins[players[team1]] += 1;
        } else{
            wins[players[team2]] +=1;
        }
        matches_played[players[team1]] +=1;
        matches_played[players[team2]] +=1;
    }
    inputFile.close();

    vector<double> res(teams);
    for(double i=0; i<teams; i++){
        res[i]=wins[i]/matches_played[i];
    }
    return res;
}

