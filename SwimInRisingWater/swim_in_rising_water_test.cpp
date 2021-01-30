/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/30
 *
 * Source : https://leetcode-cn.com/problems/swim-in-rising-water/
 * Problem: Swim in Rising Water
 *               
 */
#include <gtest/gtest.h>
#include "swim_in_rising_water.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  vector<vector<int> > grid;
  grid.push_back(vector<int>());
  grid.back().push_back(0);
  grid.back().push_back(2);
  grid.push_back(vector<int>());
  grid.back().push_back(1);
  grid.back().push_back(3);
  EXPECT_EQ(solution_.swimInWater(grid), 3);
}

