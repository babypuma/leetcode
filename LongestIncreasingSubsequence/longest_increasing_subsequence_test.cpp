/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/10
 *
 * Source : https://leetcode.com/problems/longest-increasing-subsequence/
 * Problem:	Longest Increasing Subsequence
 *
 */
#include <gtest/gtest.h>
#include "longest_increasing_subsequence.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, lengthOfLIS) {
  int a[] = {10,9,2,5,3,7,101,18};
  vector<int> vec;
  for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
    vec.push_back(a[i]);
  }
  EXPECT_EQ(solution_.lengthOfLIS(vec), 4);
}

TEST_F(SolutionTest, lengthOfLIS2) {
  int a[] = {2, 2};
  vector<int> vec;
  for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
    vec.push_back(a[i]);
  }
  EXPECT_EQ(solution_.lengthOfLIS(vec), 1);
}

