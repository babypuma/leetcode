/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/11/10
 *
 * Source : https://leetcode-cn.com/problems/last-stone-weight-ii/
 * Problem:	Last Stone Weight II
 *
 */
#include <gtest/gtest.h>
#include "last_stone_weight_ii.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {2,7,4,1,8,1};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.lastStoneWeightII(vec), 1);
}

