/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/29
 *
 * Source : https://leetcode-cn.com/problems/path-with-minimum-effort/
 * Problem: Path With Minimum Effort
 *               
 */
#include <gtest/gtest.h>
#include "path_with_minimum_effort.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  const int COL = 3;
  int h[][COL] = {
    {1,2,2},{3,8,2},{5,3,5}
  };

  vector<vector<int> > heights;
  for (size_t i = 0; i < sizeof(h)/sizeof(int[COL]); ++i) {
    heights.push_back(vector<int>());
    for (size_t j = 0; j < COL; ++j) {
      heights.back().push_back(h[i][j]);
    }
  }
  EXPECT_EQ(solution_.minimumEffortPath(heights), 2);
}

