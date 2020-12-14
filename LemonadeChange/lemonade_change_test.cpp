/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/14
 *
 * Source : https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 * Problem: Median of Two Sorted Arrays
 *               
 */
#include <gtest/gtest.h>
#include "lemonade_change.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {5,5,5,10,20};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_TRUE(solution_.lemonadeChange(vec));
}

TEST_F(SolutionTest, case2) {
  int a[] = {5,5,10,10,20};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_FALSE(solution_.lemonadeChange(vec));
}
