#include "funciones-principales.h"

using namespace std;


int main(int argc, char **argv) {

    if(argc != 4){
        printf("Parametros invalidos.\n");
        return 1;
    }

    char* input = argv[1];
    char* output = argv[2];
    int method = atoi(argv[3]);


    ifstream fileInput;
    fileInput.open(input);

    int teams;
    int matches;

    fileInput>>teams>>matches;
    vector<double> res(teams,0);


    if(method==0){
        res = cmm(teams,matches,fileInput);
    }else if(method==1){
        res = wp(teams,matches,fileInput);
    }else{
        printf("Metodo invalido.\n");
    } 


    ofstream Output;
    Output.open(output);
    for (double i = 0; i < teams; i++){
        Output << res[i] << "\n";
    }
    Output.close();

   return 0;
}

