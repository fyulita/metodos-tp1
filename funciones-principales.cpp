#include <fstream>
#include "definiciones.h"
#include "funciones-principales.h"
#include "funciones-secundarias.h"
using namespace std;

/*void gauss(matrix &M){
    int pivotRow = 0;
    int pivotColumn = 0;
    double f;
    while (pivotRow < M.size() && pivotColumn < M[0].size()){
        int iMax = pivotRow + findMaxPosition(vectorAbs(getVectorSlice(getColumn(M, pivotColumn), pivotRow, M.size())));
        if (M[iMax][pivotColumn] == 0){
            pivotColumn++;
        } else{
            swapRows(M, pivotRow, iMax);
            for (int i = pivotRow + 1; i < M.size(); i++){
                f = M[i][pivotColumn] / M[pivotRow][pivotColumn];
                M[i][pivotColumn] = 0;
                for (int j = pivotColumn + 1; j < M[0].size(); j++){
                    M[i][j] = M[i][j] - f * M[pivotRow][j];
                }
            }
            pivotRow++;
            pivotColumn++;
        }
    }
}

void gaussJordan(matrix &M){
    gauss(M);
    normalizeMatrix(M);
    double f;
    for (int row = 0; row < M.size() - 1; row++){
        for (int rowBelow = row + 1; rowBelow < M.size(); rowBelow++){
            f = M[row][rowBelow];
            for (int column = rowBelow; column < M[0].size(); column++){
                M[row][column] = M[row][column] - f * M[rowBelow][column];
            }
        }
    }
}

vector<double> findSingleSolution(matrix &M, const vector<double> &b){
    appendColumn(M, b);
    gaussJordan(M);
    vector<double> ans = getColumn(M, M[0].size() - 1);
    return ans;
}*/






void triangular_matrix(matrix& A, vector<double>& b){
    int n = A.size();
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            double m = A[j][i]/A[i][i];
            for (int k = i; k < n; k++){
                A[j][k] = A[j][k] - m * A[i][k];
            }
            b[j] = b[j] - m * b[i];
        }
    }

}




vector<double> gauss(matrix& A, vector<double>& b){
    int n = A.size();

    triangular_matrix(A,b);

    vector<double> result;

    for(int i = 0; i < n; i++){
        result.push_back(-1);
    }

    for(int i = n-1; i >= 0; i--){
        double res = b[i];
        for(int j = i+1; j < n; j++){
            res = res - A[i][j]*result[j];
        }
        result[i] = res/A[i][i];
    }
    return result;
}


vector<double> cmm (int teams, int matches,ifstream& inputFile) {

    matrix C;
    for (int i = 0; i < teams; i++) {
        C.push_back(vector<double>(teams, 0));
        C[i][i] = 2;
    }


    vector<double> wins(teams, 0);
    vector<double> looses(teams, 0);


    for (int i = 0; i < matches; i++) {
        int date,team1,score,team2,score2;
        inputFile>>date>>team1>>score>>team2>>score2;

        if (score>score2) {
            wins[team1 - 1] += 1;
            looses[team2 - 1] += 1;
        }else{
            wins[team2 - 1] += 1;
            looses[team1 - 1] += 1;
        }

        C[team1 - 1][team2 - 1] -= 1;
        C[team2 - 1][team1 - 1] -= 1;

        C[team1 - 1][team1 - 1] += 1;
        C[team2 - 1][team2 - 1] += 1;
    }
    inputFile.close();

    vector<double> b(teams, 0);
    for(int i = 0; i < teams; i++) {
        b[i] = 1 + (wins[i] - looses[i]) / 2;
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
