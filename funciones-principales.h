#ifndef SOLUCION_FUNCIONES_PRINCIPALES_H
#define SOLUCION_FUNCIONES_PRINCIPALES_H

#include "definiciones.h"

void gauss(vector<vector<double>> &M);
void gaussJordan(matrix &M);
vector<double> findSingleSolution(matrix &M, const vector<double> &b);

#endif //SOLUCION_FUNCIONES_PRINCIPALES_H
