#ifndef SOLUCION_FUNCIONES_SECUNDARIAS_H
#define SOLUCION_FUNCIONES_SECUNDARIAS_H

#include "definiciones.h"


bool equalWithError(const double &a, const double &b, const double &e);
bool equalVectors(const vector<double> &v, const vector<double> &w, const double &e);
bool equalMatrices(const vector<vector<double>> &A, const vector<vector<double>> &B, const double &e);


#endif //SOLUCION_FUNCIONES_SECUNDARIAS_H
