#include "definiciones.h"

using namespace std;


bool equalWithError(const double &a, const double &b, const double &e){
    bool ans = true;
    if (a + e < b - e || b + e < a - e){
        ans = false;
    }
    return ans;
}

bool equalVectors(const vector<double> &v, const vector<double> &w, const double &e){
    bool ans = true;
    if (v.size() != w.size()){
        ans = false;
    } else{
        for (int i = 0; i < v.size(); i++){
            if (not equalWithError(v[i], w[i], e)){
                ans = false;
            }
        }
    }
    return ans;
}

bool equalMatrices(const matrix &A, const matrix &B, const double &e){
    bool ans = true;
    if (A.size() != B.size() || A[0].size() != B[0].size()){
        ans = false;
    } else {
        for (int i = 0; i < A.size(); i++){
            if (not equalVectors(A[i], B[i], e)){
                ans = false;
            }
        }
    }
    return ans;
}


/*
float eloExpectedScore(int R1, int R2){

    return 1.0 * 1.0 / (1.0 + 1.0 * pow(10, 1.0 * (R2-R1)/400));

}


void eloRating(float& Ra, float& Rb, int k, Sa, Sb){

    //Scores esperados para ambos equipos
    float Ea = eloExpectedScore(Ra,Rb);
    float Eb = eloExpectedScore(Rb,Ra);

    //update de sus ratings post partido
    //Sa y Sb son los scores del partido
    Ra = Ra + (k * (Sa-Ea) );
    Rb = Rb + (k * (Sb-Eb) );

}
*/
