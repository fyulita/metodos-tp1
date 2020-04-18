#ifndef SOLUCION_FUNCIONES_SECUNDARIAS_H
#define SOLUCION_FUNCIONES_SECUNDARIAS_H

#include "definiciones.h"

bool equalWithError(const double &a, const double &b, const double &e);
bool equalVectors(const vector<double> &v, const vector<double> &w, const double &e);
bool equalMatrices(const vector<vector<double>> &A, const vector<vector<double>> &B, const double &e);
void swapRows(vector<vector<double>> &M, const int &m, const int &n);
int findMaxPosition(const vector<double> &v);
vector<double> getVectorSlice(const vector<double> &v, const int &i, const int &j);
vector<double> vectorAbs(const vector<double> &v);
vector<double> getColumn(const vector<vector<double>> &M, const int &i);
bool hasNoSolution(const matrix &M);
bool hasManySolutions(const matrix &M);
bool hasSingleSolution(const matrix &M);
void normalizeMatrix(matrix &M);
void appendColumn(matrix &M, const vector<double> c);

#endif //SOLUCION_FUNCIONES_SECUNDARIAS_H
