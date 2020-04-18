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
