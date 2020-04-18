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

// swapRows

TEST(swapRowsTest, swapRowsTrue){
    matrix A = {{1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}};
    matrix expected = {{1, 2, 3},
                       {7, 8, 9},
                       {4, 5, 6}};
    swapRows(A, 1, 2);
    EXPECT_EQ(A, expected);
}

TEST(swapRowsTest, swapRowsTrueInv){
    matrix A = {{1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}};
    matrix expected = {{1, 2, 3},
                       {7, 8, 9},
                       {4, 5, 6}};
    swapRows(A, 2, 1);
    EXPECT_EQ(A, expected);
}

// findMaxPosition

TEST(findMaxPositionTest, withMax){
    vector<double> v = {0, 1, 2, 1, 0};
    int expected = 2;
    int ans = findMaxPosition(v);
    EXPECT_EQ(ans, expected);
}

TEST(findMaxPositionTest, withoutMax){
    vector<double> v = {3, 3, 3, 3, 3};
    int expected = 0;
    int ans = findMaxPosition(v);
    EXPECT_EQ(ans, expected);
}

TEST(findMaxPositionTest, withoutNeg){
    vector<double> v = {3, 3, -50, 3, 3};
    int expected = 0;
    int ans = findMaxPosition(v);
    EXPECT_EQ(ans, expected);
}

// getVectorSlice

TEST(getVectorSliceTest, all){
    vector<double> v = {3, 3, -50, 3, 3};
    vector<double> ans = getVectorSlice(v, 0, v.size());
    double e = 1e-9;
    bool equal = equalVectors(v, ans, e);
    EXPECT_TRUE(equal);
}

TEST(getVectorSliceTest, frombeginning){
    vector<double> v = {3, 3, -50, 3, 3};
    vector<double> ans = getVectorSlice(v, 0, 3);
    vector<double> expected = {3, 3, -50};
    double e = 1e-9;
    bool equal = equalVectors(expected, ans, e);
    EXPECT_TRUE(equal);
}

// vectorAbs

TEST(vectorAbsTest, allPositive){
    vector<double> v = {3, 3, 50, 3, 3};
    vector<double> ans = vectorAbs(v);
    double e = 1e-9;
    bool equal = equalVectors(v, ans, e);
    EXPECT_TRUE(equal);
}

TEST(vectorAbsTest, mixed){
    vector<double> v = {3, -3, 0, 8, -15.2};
    vector<double> ans = vectorAbs(v);
    vector<double> expected = {3, 3, 0, 8, 15.2};
    double e = 1e-9;
    bool equal = equalVectors(expected, ans, e);
    EXPECT_TRUE(equal);
}

// getColumn

TEST(getColumnTest, identity2_1) {
    matrix M = {{1, 0},
                {0, 1}};
    vector<double> ans = getColumn(M, 0);
    vector<double> expected = {1, 0};
    double e = 1e-9;
    bool equal = equalVectors(expected, ans, e);
    EXPECT_TRUE(equal);
}

TEST(getColumnTest, identity2_2) {
    matrix M = {{1, 0},
                {0, 1}};
    vector<double> ans = getColumn(M, 1);
    vector<double> expected = {0, 1};
    double e = 1e-9;
    bool equal = equalVectors(expected, ans, e);
    EXPECT_TRUE(equal);
}
