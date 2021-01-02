/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/02
 *
 * Source : https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
 * Problem:	Search a 2D Matrix II
 *
 */
#include <gtest/gtest.h>
#include "search_a_2d_matrix_ii.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  vector<vector<int> > vec2d;
  int a[][5] = {{1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22}, {10,13,14,17,24},{18,21,23,26,30}};
  for (size_t i = 0; i < sizeof(a)/sizeof(int[5]); i++) {
    vector<int> vec(a[i], a[i] + sizeof(a[i])/sizeof(a[i][0]));
    vec2d.push_back(vec);
  }
  EXPECT_TRUE(solution_.searchMatrix(vec2d, 5));
  EXPECT_TRUE(solution_.searchMatrix(vec2d, 23));
  EXPECT_FALSE(solution_.searchMatrix(vec2d, 0));
  EXPECT_FALSE(solution_.searchMatrix(vec2d, 20));
}

