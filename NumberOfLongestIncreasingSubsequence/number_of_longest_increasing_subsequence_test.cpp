/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/10
 *
 * Source : https://leetcode.com/problems/number-of-longest-increasing-subsequence/
 * Problem:	Number of Longest Increasing Subsequence
 *
 */
#include <gtest/gtest.h>
#include "number_of_longest_increasing_subsequence.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, findNumberOfLIS) {
  int a[] = {1,3,5,4,7};
  vector<int> vec;
  for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
    vec.push_back(a[i]);
  }
  EXPECT_EQ(solution_.findNumberOfLIS(vec), 2);
}

TEST_F(SolutionTest, findNumberOfLIS2) {
  int a[] = {2,2,2,2,2};
  vector<int> vec;
  for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
    vec.push_back(a[i]);
  }
  EXPECT_EQ(solution_.findNumberOfLIS(vec), 5);
}

TEST_F(SolutionTest, findNumberOfLIS3) {
  int a[] = {1,2,4,3,5,4,7,2};
  vector<int> vec;
  for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
    vec.push_back(a[i]);
  }
  EXPECT_EQ(solution_.findNumberOfLIS(vec), 3);
}

TEST_F(SolutionTest, findNumberOfLIS4) {
  int a[] = {1,1,1,2,2,2,3,3,3};
  vector<int> vec;
  for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
    vec.push_back(a[i]);
  }
  EXPECT_EQ(solution_.findNumberOfLIS(vec), 27);
}

