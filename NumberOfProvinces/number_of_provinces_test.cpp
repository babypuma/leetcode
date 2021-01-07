/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/07
 *
 * Source : https://leetcode-cn.com/problems/number-of-provinces/
 * Problem: Number of Provinces
 *               
 */
#include <gtest/gtest.h>
#include "number_of_provinces.h"

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
  matrix.back().push_back(1);
  matrix.back().push_back(1);
  matrix.back().push_back(0);
  matrix.push_back(vector<int>());
  matrix.back().push_back(1);
  matrix.back().push_back(1);
  matrix.back().push_back(0);
  matrix.push_back(vector<int>());
  matrix.back().push_back(0);
  matrix.back().push_back(0);
  matrix.back().push_back(1);
  EXPECT_EQ(solution_.findCircleNum(matrix), 2);
}

TEST_F(SolutionTest, case2) {
  vector<vector<int> > matrix;
  matrix.push_back(vector<int>());
  matrix.back().push_back(1);
  matrix.back().push_back(0);
  matrix.back().push_back(0);
  matrix.back().push_back(1);
  matrix.push_back(vector<int>());
  matrix.back().push_back(0);
  matrix.back().push_back(1);
  matrix.back().push_back(1);
  matrix.back().push_back(0);
  matrix.push_back(vector<int>());
  matrix.back().push_back(0);
  matrix.back().push_back(1);
  matrix.back().push_back(1);
  matrix.back().push_back(1);
  matrix.push_back(vector<int>());
  matrix.back().push_back(1);
  matrix.back().push_back(0);
  matrix.back().push_back(1);
  matrix.back().push_back(1);
  EXPECT_EQ(solution_.findCircleNum(matrix), 1);
}

