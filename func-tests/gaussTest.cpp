#include "gtest/gtest.h"
#include "../funciones-principales.h"
#include "../funciones-secundarias.h"

TEST(gaussTest, identity2) {
    matrix M = {{1, 0},
                {0, 1}};
    matrix expected = M;
    gauss(M);
    bool ans = equalMatrices(M, expected);
    EXPECT_TRUE(ans);
}

TEST(gaussTest, identity3) {
    matrix M = {{1, 0, 0},
                {0, 1, 0},
                {0, 0, 1}};
    matrix expected = M;
    gauss(M);
    bool ans = equalMatrices(M, expected);
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
    bool ans = equalMatrices(M, expected);
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
    bool ans = equalMatrices(M, expected);
    EXPECT_TRUE(ans);
}
