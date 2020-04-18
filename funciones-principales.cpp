#include "definiciones.h"
#include "funciones-secundarias.h"

void gauss(matrix &M){
    int pivotRow = 0;
    int pivotColumn = 0;
    while (pivotRow < M.size() && pivotColumn < M[0].size()){
        int iMax = pivotRow + findMaxPosition(vectorAbs(getVectorSlice(getColumn(M, pivotColumn), pivotRow, M.size())));
        if (M[iMax][pivotColumn] == 0){
            pivotColumn++;
        } else{
            swapRows(M, pivotRow, iMax);
            for (int i = pivotRow + 1; i < M.size(); i++){
                double f = M[i][pivotColumn] / M[pivotRow][pivotColumn];
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






void triangular_matrix(matrix A, vector<double> b){
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




vector<double> gausss(matrix A, vector<double> b){    
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
        result[i] = A[i][i]/res;
    }
    return result;
}
