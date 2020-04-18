#ifndef SOLUCION_FUNCIONES_PRINCIPALES_H
#define SOLUCION_FUNCIONES_PRINCIPALES_H

#include "definiciones.h"

void gauss(vector<vector<double>> &M);

void triangular_matrix(matrix A, vector<double> b,matrix Aaux, vector<double> baux);
vector<double> gausss(matrix A, vector<double> b);



#endif //SOLUCION_FUNCIONES_PRINCIPALES_H
