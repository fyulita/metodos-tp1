#ifndef SOLUCION_FUNCIONES_SECUNDARIAS_H
#define SOLUCION_FUNCIONES_SECUNDARIAS_H

#include "definiciones.h"

bool equalMatrices(const vector<vector<double>> &A, const vector<vector<double>> &B);
bool equalVectors(const vector<double> &v, const vector<double> &w);
void swapRows(vector<vector<double>> &M, const int &m, const int &n);
int findMaxPosition(const vector<double> &v);
vector<double> getVectorSlice(const vector<double> &v, const int &i, const int &j);
vector<double> vectorAbs(const vector<double> &v);
vector<double> getColumn(const vector<vector<double>> &M, const int &i);

#endif //SOLUCION_FUNCIONES_SECUNDARIAS_H
