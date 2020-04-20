#ifndef SOLUCION_FUNCIONES_PRINCIPALES_H
#define SOLUCION_FUNCIONES_PRINCIPALES_H

#include "definiciones.h"
#include <fstream>
using namespace std;


void gauss(vector<vector<double>> &M);
void gaussJordan(matrix &M);
vector<double> findSingleSolution(matrix &M, const vector<double> &b);
vector<double> cmm (int teams,int matches,ifstream& inputFile);


#endif //SOLUCION_FUNCIONES_PRINCIPALES_H
