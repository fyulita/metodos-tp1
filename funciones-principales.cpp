#include "definiciones.h"
#include "funciones-secundarias.h"

void gauss(matrix &M){
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
}


//matches representa a una matriz de 2 columnas por la cantidad de partidos en filas
//en la primer columna estan los ganadores de dichos partidos y en la otra los perdedores

vector<double> cmm (int teams, vector<vector<int> >& matches) {

    matrix C;
    for (int i = 0; i < teams; i++) {
        C.push_back(vector<double>(teams, 0));
        C[i][i] = 2;
    }


    vector<double> wins(teams, 0);
    vector<double> looses(teams, 0);


    for (int i = 0; i < matches.size(); i++) {
        wins[matches[i][0]-1] += 1;
        looses[matches[i][1]-1] += 1;



        C[matches[i][0]-1][matches[i][1]-1] -= 1;
        C[matches[i][1]-1][matches[i][0]-1] -= 1;

        C[matches[i][0]-1][matches[i][0]-1] += 1;
        C[matches[i][1]-1][matches[i][1]-1] += 1;


    }

    vector<double> b(teams, 0);
    for(int i = 0; i < teams; i++) {
        b[i] = 1 + (wins[i] - looses[i]) / 2;
    }

    return findSingleSolution(C,b);
}

