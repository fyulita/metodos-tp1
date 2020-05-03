#include "funciones-secundarias.h"
#include <fstream>
using namespace std;



vector<double> cmm (int teams, int matches, ifstream& inputFile) {
    
    //Primero creamos la matriz 
    matrix C;
    for (int i = 0; i < teams; i++) {
        C.push_back(vector<double>(teams, 0));
        C[i][i] = 2;
    }


    vector<double> wins(teams, 0);
    vector<double> losses(teams, 0);

    //Llenamos la matriz C
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
    
    //Creamos el vector B
    vector<double> b(teams, 0);
    for(int i = 0; i < teams; i++) {
        b[i] = 1 + (wins[i] - losses[i]) / 2;
    }
    
    //Aplicamos metodo gaussiano
    return gauss(C,b);
}



//WP devuelve un vector con los ratings de todos los equipos
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

    vector<double> res(teams,0);
    for(int i=0; i<teams; i++){
        res[i]=wins[i]/matches_played[i];
    }
    return res;
}


// Usamos league para devolver la puntuacion oficial de la premier league con la excepcion de que,
// en caso de empate, se diera por victoria al equipo visitante.
vector<double> league(int teams, int matches,ifstream& inputFile){
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

    vector<double> res(teams,0);
    for(int i=0; i<teams; i++){
        res[i]=wins[i]*3; //El ganador de un partido obtiene 3 puntos, mientras que el perdedor 0.
    }
    return res;
}


