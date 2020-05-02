#ifndef SOLUCION_FUNCIONES_PRINCIPALES_H
#define SOLUCION_FUNCIONES_PRINCIPALES_H

#include "definiciones.h"
#include <fstream>


vector<double> cmm (int teams,int matches,ifstream& inputFile);
vector<double> wp(int teams, int matches,ifstream& inputFile);
vector<double> league(int teams, int matches,ifstream& inputFile);


#endif 
