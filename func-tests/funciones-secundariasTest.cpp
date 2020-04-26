#include "gtest/gtest.h"
#include "../funciones-secundarias.h"

// equalVectors

TEST(equalVectorsTest, equalVectors){
    vector<double> v = {1, 2, 3};
    double e = 1e-9;
    EXPECT_TRUE(equalVectors(v, v, e));
}

TEST(equalVectorsTest, diffVectors){
    vector<double> v = {1, 2, 3};
    vector<double> w = {1, 3, 3};
    double e = 1e-9;
    EXPECT_FALSE(equalVectors(v, w, e));
}

// equalMatrices

TEST(equalMatricesTest, equalMatrices){
    matrix A = {{1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}};
    double e = 1e-9;
    EXPECT_TRUE(equalMatrices(A, A, e));
}

TEST(equalMatricesTest, diffMatrices){
    matrix A = {{1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}};
    matrix B = {{1, 2, 3},
                {4, 6, 6},
                {7, 8, 9}};
    double e = 1e-9;
    EXPECT_FALSE(equalMatrices(A, B, e));
}
