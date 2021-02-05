/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/06
 *
 * Source : https://leetcode-cn.com/problems/reducing-dishes/
 * Problem: Reducing Dishes
 *               
 */
#include <gtest/gtest.h>
#include "reducing_dishes.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {-1,-8,0,5,-9};
  vector<int> sat(a, a + sizeof(a) / sizeof(a[0]));
  EXPECT_EQ(solution_.maxSatisfaction(sat), 14);
}

