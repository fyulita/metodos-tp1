#include "gtest/gtest.h"
#include "../funciones-principales.h"
#include "../funciones-secundarias.h"

double e = 1e-9;

TEST(gaussTest, identity2) {
    matrix M = {{1, 0},
                {0, 1}};
    matrix expected = M;
    gauss(M);
    bool ans = equalMatrices(M, expected, e);
    EXPECT_TRUE(ans);
}

TEST(gaussTest, identity3) {
    matrix M = {{1, 0, 0},
                {0, 1, 0},
                {0, 0, 1}};
    matrix expected = M;
    gauss(M);
    bool ans = equalMatrices(M, expected, e);
    EXPECT_TRUE(ans);
}

TEST(gaussTest, permIdentity3) {
    matrix M = {{0, 1, 0},
                {0, 0, 1},
                {1, 0, 0}};
    matrix expected = {{1, 0, 0},
                       {0, 1, 0},
                       {0, 0, 1}};
    gauss(M);
    bool ans = equalMatrices(M, expected, e);
    EXPECT_TRUE(ans);
}

TEST(gaussTest, sameRows) {
    matrix M = {{1, 2, 0},
                {0, 0, 6},
                {1, 2, 0}};
    matrix expected = {{1, 2, 0},
                       {0, 0, 6},
                       {0, 0, 0}};
    gauss(M);
    bool ans = equalMatrices(M, expected, e);
    EXPECT_TRUE(ans);
}

TEST(gaussTest, manySolutions_1) {
    matrix M = {{1, 0, 8, 0},
                {0, 4, 0, 9},
                {0, 0, 1, 3}};
    matrix expected = M;
    gauss(M);
    bool ans = equalMatrices(M, expected, e);
    EXPECT_TRUE(ans);
}

TEST(gaussTest, manySolutions_2) {
    matrix M = {{1, 0, 8, 0},
                {1, 4, 0, 9},
                {0, 0, 1, 3}};
    matrix expected = {{1, 0, 8, 0},
                       {0, 4, -8, 9},
                       {0, 0, 1, 3}};
    gauss(M);
    bool ans = equalMatrices(M, expected, e);
    EXPECT_TRUE(ans);
}

TEST(gaussTest, manySolutions_3) {
    matrix M = {{1, 0, 8, 0},
                {1, 4, 0, 9},
                {0, 7, 1, 3}};
    matrix expected = {{1, 0, 8, 0},
                       {0, 7, 1, 3},
                       {0, 0, (double)-60 / (double)7, (double)51 / (double)7}};
    gauss(M);
    bool ans = equalMatrices(M, expected, e);
    EXPECT_TRUE(ans);
}

// gaussJordan

TEST(gaussJordanTest, identity2) {
    matrix M = {{1, 0},
                {0, 1}};
    matrix expected = M;
    gaussJordan(M);
    bool ans = equalMatrices(M, expected, e);
    EXPECT_TRUE(ans);
}

TEST(gaussJordanTest, identity3) {
    matrix M = {{1, 0, 0},
                {0, 1, 0},
                {0, 0, 1}};
    matrix expected = M;
    gaussJordan(M);
    bool ans = equalMatrices(M, expected, e);
    EXPECT_TRUE(ans);
}

TEST(gaussJordanTest, permIdentity3) {
    matrix M = {{0, 1, 0},
                {0, 0, 1},
                {1, 0, 0}};
    matrix expected = {{1, 0, 0},
                       {0, 1, 0},
                       {0, 0, 1}};
    gaussJordan(M);
    bool ans = equalMatrices(M, expected, e);
    EXPECT_TRUE(ans);
}

TEST(gaussJordanTest, sameRows) {
    matrix M = {{1, 2, 0},
                {0, 0, 6},
                {1, 2, 0}};
    matrix expected = {{1, 2, 0},
                       {0, 0, 1},
                       {0, 0, 0}};
    gaussJordan(M);
    bool ans = equalMatrices(M, expected, e);
    EXPECT_TRUE(ans);
}

TEST(gaussJordanTest, manySolutions_1) {
    matrix M = {{1, 0, 8, 0},
                {0, 4, 0, 9},
                {0, 0, 1, 3}};
    matrix expected = {{1, 0, 0, -24},
                       {0, 1, 0, (double)9 / (double)4},
                       {0, 0, 1, 3}};
    gaussJordan(M);
    bool ans = equalMatrices(M, expected, e);
    EXPECT_TRUE(ans);
}

TEST(gaussJordanTest, manySolutions_2) {
    matrix M = {{1, 0, 8, 0},
                {1, 4, 0, 9},
                {0, 0, 1, 3}};
    matrix expected = {{1, 0, 0, -24},
                       {0, 1, 0, (double)33 / (double)4},
                       {0, 0, 1, 3}};
    gaussJordan(M);
    bool ans = equalMatrices(M, expected, e);
    EXPECT_TRUE(ans);
}

TEST(gaussJordanTest, manySolutions_3) {
    matrix M = {{1, 0, 8, 0},
                {1, 4, 0, 9},
                {0, 7, 1, 3}};
    matrix expected = {{1, 0, 0, (double)102 / (double)15},
                       {0, 1, 0, (double)11 / (double)20},
                       {0, 0, 1, -(double)51 / (double)60}};
    gaussJordan(M);
    bool ans = equalMatrices(M, expected, e);
    EXPECT_TRUE(ans);
}

// findSingleSolution

TEST(findSingleSolutionTest, identity2) {
    matrix M = {{1, 0},
                {0, 1}};
    vector<double> b = {3, 4};
    vector<double> ans = findSingleSolution(M, b);
    bool equal = equalVectors(b, ans, e);
    EXPECT_TRUE(equal);
}

TEST(findSingleSolutionTest, identity3) {
    matrix M = {{1, 0, 0},
                {0, 1, 0},
                {0, 0, 1}};
    vector<double> b = {3, 4, -(double)7 / (double)11};
    vector<double> ans = findSingleSolution(M, b);
    bool equal = equalVectors(b, ans, e);
    EXPECT_TRUE(equal);
}

TEST(findSingleSolutionTest, permIdentity3) {
    matrix M = {{0, 1, 0},
                {0, 0, 1},
                {1, 0, 0}};
    vector<double> b = {3, 7, -(double)7 / (double)11};
    vector<double> expected = {-(double)7 / (double)11, 3, 7};
    vector<double> ans = findSingleSolution(M, b);
    bool equal = equalVectors(expected, ans, e);
    EXPECT_TRUE(equal);
}

TEST(findSingleSolutionTest, manySolutions_1) {
    matrix M = {{1, 0, 8},
                {0, 4, 0},
                {0, 0, 1}};
    vector<double> b = {0, 9, 3};
    vector<double> expected = {-24, (double)9 / (double)4, 3};
    vector<double> ans = findSingleSolution(M, b);
    bool equal = equalVectors(expected, ans, e);
    EXPECT_TRUE(equal);
}

TEST(findSingleSolutionTest, manySolutions_2) {
    matrix M = {{1, 0, 8},
                {1, 4, 0},
                {0, 0, 1}};
    vector<double> b = {0, 9, 3};
    vector<double> expected = {-24, (double)33 / (double)4, 3};
    vector<double> ans = findSingleSolution(M, b);
    bool equal = equalVectors(expected, ans, e);
    EXPECT_TRUE(equal);
}

TEST(findSingleSolutionTest, manySolutions_3) {
    matrix M = {{1, 0, 8},
                {1, 4, 0},
                {0, 7, 1}};
    vector<double> b = {0, 9, 3};
    vector<double> expected = {(double)102 / (double)15, (double)11 / (double)20, -(double)51 / (double)60};
    vector<double> ans = findSingleSolution(M, b);
    bool equal = equalVectors(expected, ans, e);
    EXPECT_TRUE(equal);
}
