/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/17
 *
 * Source : https://leetcode-cn.com/problems/reshape-the-matrix/
 * Problem: Reshape The Matrix
 *               
 */
#include <gtest/gtest.h>
#include "reshape_the_matrix.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  vector<vector<int> > nums;
  nums.push_back(vector<int>());
  nums.back().push_back(1);
  nums.back().push_back(2);
  nums.push_back(vector<int>());
  nums.back().push_back(3);
  nums.back().push_back(4);
  vector<vector<int> > m = solution_.matrixReshape(nums, 1, 4);
  EXPECT_EQ(m.size(), 1);
  for (size_t i = 0; i < 4; ++i) {
    EXPECT_EQ(m[0][i], i + 1);
  }
}

