/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/26
 *
 * Source : https://leetcode-cn.com/problems/largest-submatrix-with-rearrangements/
 * Problem: Largest Submatrix With Rearrangements
 *               
 */
#include <gtest/gtest.h>
#include "largest_submatrix_with_rearrangements.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  vector<vector<int> > matrix;
  matrix.push_back(vector<int>());
  matrix.back().push_back(0);
  matrix.back().push_back(0);
  matrix.back().push_back(1);
  matrix.push_back(vector<int>());
  matrix.back().push_back(1);
  matrix.back().push_back(1);
  matrix.back().push_back(1);
  matrix.push_back(vector<int>());
  matrix.back().push_back(1);
  matrix.back().push_back(0);
  matrix.back().push_back(1);
  EXPECT_EQ(solution_.largestSubmatrix(matrix), 4);
}

