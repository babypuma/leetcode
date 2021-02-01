/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/01
 *
 * Source : https://leetcode-cn.com/problems/fair-candy-swap/
 * Problem: Fair Candy Swap
 *               
 */
#include <gtest/gtest.h>
#include "fair_candy_swap.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1, 1};
  vector<int> A(a, a + sizeof(a) / sizeof(a[0]));
  int b[] = {2, 2};
  vector<int> B(b, b + sizeof(b) / sizeof(b[0]));
  vector<int> s = solution_.fairCandySwap(A, B);
  EXPECT_EQ(s.size(), 2);
  EXPECT_EQ(s[0], 1);
  EXPECT_EQ(s[1], 2);
}

