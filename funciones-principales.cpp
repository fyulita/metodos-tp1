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






void triangular_matrix(matrix A, vector<double> b,matrix Aaux, vector<double> baux){
    int n = A.size();
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            double m = A[j][i]/A[i][i];
            for (int k = i; k < n; k++){
                double y = -m * A[i][k];
                double t = A[j][k] + y;
                Aaux[j][k] = (t - A[j][k]) - y;
                A[j][k] = t;
            }
            double y = -m * b[i];
            double t = b[j] + y;
            baux[j] = (t - b[j]) - y;
            b[j] = t;
        }
    }

}




vector<double> gausss(matrix A, vector<double> b){    
    int n = A.size();

    matrix Aaux;
    vector<double> baux;
    for(int i = 0; i < n; i++){  
        vector<double> row;
        for(int j = 0; j < n; j++){
            row.push_back(0);
        }
        Aaux.push_back(row);
        baux.push_back(0);
    }
    
    triangular_matrix(A,b,Aaux,baux);
    
    vector<double> resultado;

    for(int i = 0; i < n; i++){
        resultado.push_back(-1);
    }

    for(int i = n-1; i >= 0; i--){
        double res = b[i];
        double c = 0;
        for(int j = i+1; j < n; j++){
            double y = -A[i][j]*resultado[j];
            double t = res + y;
            c = (t - res) - y;
            res = t;
        }
        res /= A[i][i];
        resultado[i] = res;
    }
    return resultado;
}
