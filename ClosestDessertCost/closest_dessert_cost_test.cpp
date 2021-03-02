/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/01
 *
 * Source : https://leetcode-cn.com/problems/closest-dessert-cost/
 * Problem: Closest Dessert Cost
 *               
 */
#include <gtest/gtest.h>
#include "closest_dessert_cost.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,7};
  vector<int> baseCosts(a, a + sizeof(a)/sizeof(a[0]));
  int b[] = {3,4};
  vector<int> toppingCosts(b, b + sizeof(b)/sizeof(b[0]));
  EXPECT_EQ(solution_.closestCost(baseCosts, toppingCosts, 10), 10);
}

