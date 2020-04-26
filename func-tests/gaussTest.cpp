#include "gtest/gtest.h"
#include "../funciones-principales.h"
#include "../funciones-secundarias.h"

double e = 1e-9;


// findSingleSolution

TEST(gaussTest, identity2) {
    matrix M = {{1, 0},
                {0, 1}};
    vector<double> b = {3, 4};
    vector<double> ans = gauss(M, b);
    bool equal = equalVectors(b, ans, e);
    EXPECT_TRUE(equal);
}

TEST(gaussTest, identity3) {
    matrix M = {{1, 0, 0},
                {0, 1, 0},
                {0, 0, 1}};
    vector<double> b = {3, 4, -(double)7 / (double)11};
    vector<double> ans = gauss(M, b);
    bool equal = equalVectors(b, ans, e);
    EXPECT_TRUE(equal);
}

TEST(gaussTest, permIdentity3) {
    matrix M = {{0, 1, 0},
                {0, 0, 1},
                {1, 0, 0}};
    vector<double> b = {3, 7, -(double)7 / (double)11};
    vector<double> expected = {-(double)7 / (double)11, 3, 7};
    vector<double> ans = gauss(M, b);
    bool equal = equalVectors(expected, ans, e);
    EXPECT_TRUE(equal);
}

TEST(gaussTest, manySolutions_1) {
    matrix M = {{1, 0, 8},
                {0, 4, 0},
                {0, 0, 1}};
    vector<double> b = {0, 9, 3};
    vector<double> expected = {-24, (double)9 / (double)4, 3};
    vector<double> ans = gauss(M, b);
    bool equal = equalVectors(expected, ans, e);
    EXPECT_TRUE(equal);
}

TEST(gaussTest, manySolutions_2) {
    matrix M = {{1, 0, 8},
                {1, 4, 0},
                {0, 0, 1}};
    vector<double> b = {0, 9, 3};
    vector<double> expected = {-24, (double)33 / (double)4, 3};
    vector<double> ans = gauss(M, b);
    bool equal = equalVectors(expected, ans, e);
    EXPECT_TRUE(equal);
}

TEST(gaussTest, manySolutions_3) {
    matrix M = {{1, 0, 8},
                {1, 4, 0},
                {0, 7, 1}};
    vector<double> b = {0, 9, 3};
    vector<double> expected = {(double)102 / (double)15, (double)11 / (double)20, -(double)51 / (double)60};
    vector<double> ans = gauss(M, b);
    bool equal = equalVectors(expected, ans, e);
    EXPECT_TRUE(equal);
}
