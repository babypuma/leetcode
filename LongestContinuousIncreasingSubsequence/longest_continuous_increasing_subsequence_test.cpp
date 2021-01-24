/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/24
 *
 * Source : https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/
 * Problem: Longest Continuous Increasing Subsequence
 *
 */
#include <gtest/gtest.h>
#include "longest_continuous_increasing_subsequence.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,3,5,4,7};
  vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
  EXPECT_EQ(solution_.findLengthOfLCIS(v), 3);
}

TEST_F(SolutionTest, case2) {
  int a[] = {2,2,2,2,2};
  vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
  EXPECT_EQ(solution_.findLengthOfLCIS(v), 1);
}

