/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/19
 *
 * Source : https://leetcode-cn.com/problems/positions-of-large-groups/
 * Problem:	Positions of Large Groups
 *
 */
#include <gtest/gtest.h>
#include "position_of_large_groups.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, largeGroupPositions) {
  vector<vector<int> > vec2 = solution_.largeGroupPositions("abbxxxxzzy");
  EXPECT_EQ(vec2.size(), 1);
}

