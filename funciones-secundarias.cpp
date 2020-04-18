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

bool equalVectors(const vector<double> &v, const vector<double> &w){
    bool ans = true;
    if (v.size() != w.size()){
        ans = false;
    } else{
        for (int i = 0; i < v.size(); i++){
            if (v[i] != w[i]){
                ans = false;
            }
        }
    }
    return ans;
}

bool equalMatrices(const matrix &A, const matrix &B){
    bool ans = true;
    if (A.size() != B.size() || A[0].size() != B[0].size()){
        ans = false;
    } else {
        for (int i = 0; i < A.size(); i++){
            for (int j = 0; j < A[0].size(); j++){
                if (A[i][j] != B[i][j]){
                    ans = false;
                }
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
