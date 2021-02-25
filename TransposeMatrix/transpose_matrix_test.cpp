/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/25
 *
 * Source : https://leetcode-cn.com/problems/transpose-matrix/
 * Problem: Transpose Matrix
 *               
 */
#include <gtest/gtest.h>
#include "transpose_matrix.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  vector<vector<int> > m;
  m.push_back(vector<int>());
  m.back().push_back(2);
  m.back().push_back(4);
  m.back().push_back(-1);
  m.push_back(vector<int>());
  m.back().push_back(-10);
  m.back().push_back(5);
  m.back().push_back(11);
  m.push_back(vector<int>());
  m.back().push_back(18);
  m.back().push_back(-7);
  m.back().push_back(6);

  vector<vector<int> > m2 = solution_.transpose(m);
  EXPECT_EQ(m2.size(), 3);
  EXPECT_EQ(m2[0][0], 2);
  EXPECT_EQ(m2[0][1], -10);
  EXPECT_EQ(m2[0][2], 18);
  EXPECT_EQ(m2[1][0], 4);
  EXPECT_EQ(m2[1][1], 5);
  EXPECT_EQ(m2[1][2], -7);
  EXPECT_EQ(m2[2][0], -1);
  EXPECT_EQ(m2[2][1], 11);
  EXPECT_EQ(m2[2][2], 6);
}

