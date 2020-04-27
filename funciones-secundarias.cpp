#include "definiciones.h"


/* Pre: Matriz cuadrada */
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


/* Pre: Matriz SCD */
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


