/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/30
 *
 * Source : https://leetcode-cn.com/problems/last-stone-weight/
 * Problem:	Last Stone Weight
 *
 */
#include <gtest/gtest.h>
#include "last_stone_weight.h"

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
  EXPECT_EQ(solution_.lastStoneWeight(vec), 1);
}

