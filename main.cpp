#include "gtest/gtest.h"
#include <fstream>
#include "funciones-principales.h"
using namespace std;

int main(int argc, char **argv) {

    if(argc != 4){
        printf("Parametros invalidos.\n");
        return 1;
    }

    int method = atoi(argv[1]);
    char* input = argv[2];
    char* output = argv[3];


    ifstream fileInput;
    fileInput.open(input);

    int teams;
    int matches;

    fileInput>>teams>>matches;

    if(method==0){
        cmm(teams,matches,fileInput);
    }

   // testing::InitGoogleTest(&argc, argv);
   // return RUN_ALL_TESTS();
   return 0;
}
