/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/27
 *
 * Source : https://leetcode-cn.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/
 * Problem: Minimum Deletion Cost to Avoid Repeating Letters
 *               
 */
#include <gtest/gtest.h>
#include "minimum_deletion_cost_to_avoid_repeating_letters.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,2,3,4,5};
  vector<int> cost(a, a + sizeof(a)/sizeof(a[0]));
  string s("abaac");
  EXPECT_EQ(solution_.minCost(s, cost), 3);
}

TEST_F(SolutionTest, case2) {
  int a[] = {1,2,3,4,1};
  vector<int> cost(a, a + sizeof(a)/sizeof(a[0]));
  string s("aabaa");
  EXPECT_EQ(solution_.minCost(s, cost), 2);
}

