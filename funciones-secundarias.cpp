#include "definiciones.h"

using namespace std;

bool isMatrix(const vector<vector<double>> &M){
    bool ans = true;
    for (int i = 0; i < M.size(); i++){
        if (M.size() != M[i].size()){
            ans = false;
        }
    }
    return ans;
}

bool equalWithError(const double &a, const double &b, const double &e){
    bool ans = true;
    if (a + e < b - e || b + e < a - e){
        ans = false;
    }
    return ans;
}

bool equalVectors(const vector<double> &v, const vector<double> &w, const double &e){
    bool ans = true;
    if (v.size() != w.size()){
        ans = false;
    } else{
        for (int i = 0; i < v.size(); i++){
            if (not equalWithError(v[i], w[i], e)){
                ans = false;
            }
        }
    }
    return ans;
}

bool equalMatrices(const matrix &A, const matrix &B, const double &e){
    bool ans = true;
    if (A.size() != B.size() || A[0].size() != B[0].size()){
        ans = false;
    } else {
        for (int i = 0; i < A.size(); i++){
            if (not equalVectors(A[i], B[i], e)){
                ans = false;
            }
        }
    }
    return ans;
}

void swapRows(matrix &M, const int &m, const int &n){
    vector<double> aux = M[m];
    M[m] = M[n];
    M[n] = aux;
}

int findMaxPosition(const vector<double> &v){
    double max = v[0];
    int maxPosition = 0;
    for (int i = 1; i < v.size(); i++){
        if (v[i] > max){
            max = v[i];
            maxPosition = i;
        }
    }
    return maxPosition;
}

vector<double> getVectorSlice(const vector<double> &v, const int &i, const int &j){
    vector<double> ans;
    for (int k = i; k < j; k++){
        ans.push_back(v[k]);
    }
    return ans;
}

double absVal(const double &x){
    double ans = x;
    if (x < 0){
        ans = -x;
    }
    return ans;
}

vector<double> vectorAbs(const vector<double> &v){
    vector<double> ans;
    for (int i = 0; i < v.size(); i++){
        ans.push_back(absVal(v[i]));
    }
    return ans;
}

vector<double> getColumn(const matrix &M, const int &i) {
    vector<double> ans;
    for (int j = 0; j < M.size(); j++) {
        ans.push_back(M[j][i]);
    }
    return ans;
}

bool zeroVector(const vector<double> &v){
    bool ans = true;
    for (int i = 0; i < v.size(); i++){
        if (v[i] != 0){
            ans = false;
        }
    }
    return ans;
}

bool hasNoSolution(const matrix &M){
    bool ans = true;
    for (int i = 0; i < M.size(); i++){
        if (not zeroVector(M[i])){
            ans = false;
        }
    }
    return ans;
}

bool hasManySolutions(const matrix &M){
    bool ans = M.size() < M[0].size();
    return ans;
}

bool hasSingleSolution(const matrix &M){
    bool ans = (not hasNoSolution(M)) && (not hasManySolutions(M));
    return ans;
}

double firstNonZero(const vector<double> &v){
    double ans = 0;
    int i = 0;
    while (i < v.size() && ans == 0){
        if (v[i] != 0){
            ans = v[i];
        }
        i++;
    }
    return ans;
}

void normalizeVector(vector<double> &v){
    double f = (double)1 / firstNonZero(v);
    for (int i = 0; i < v.size(); i++){
        v[i] = f * v[i];
    }
}

void normalizeMatrix(matrix &M){
    for (int i = 0; i < M.size(); i++){
        normalizeVector(M[i]);
    }
}

void appendColumn(matrix &M, const vector<double> c){
    for (int i = 0; i < M.size(); i++){
        M[i].push_back(c[i]);
    }
}
