/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/29
 *
 * Source : https://leetcode-cn.com/problems/perfect-squares/
 * Problem:	Perfect Squares
 *
 */
#include <gtest/gtest.h>
#include "perfect_squares.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, numSquares) {
  EXPECT_EQ(solution_.numSquares(12), 3);
  EXPECT_EQ(solution_.numSquares(13), 2);
  EXPECT_EQ(solution_.numSquares(27), 3);
}

TEST_F(SolutionTest, numSquares2) {
  EXPECT_EQ(solution_.numSquares(60), 4);
}

TEST_F(SolutionTest, numSquares3) {
  EXPECT_EQ(solution_.numSquares(7168), 4);
}

TEST_F(SolutionTest, numSquares4) {
  EXPECT_EQ(solution_.numSquares(6616), 3);
}

