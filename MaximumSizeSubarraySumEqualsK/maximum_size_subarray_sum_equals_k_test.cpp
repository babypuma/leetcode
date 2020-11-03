/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/11/03
 *
 * Source : https://leetcode-cn.com/problems/maximum-size-subarray-sum-equals-k/
 * Problem:	Maximum Size Subarray Sum Equals K
 *
 */
#include <gtest/gtest.h>
#include "maximum_size_subarray_sum_equals_k.h"

TEST(NumArray, maxSubArrayLen) {
  int a[] = {1, -1, 5, -2, 3};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  Solution solution;
  EXPECT_EQ(solution.maxSubArrayLen(vec, 3), 4);
}

TEST(NumArray, maxSubArrayLen2) {
  int a[] = {-2, -1, 2, 1};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  Solution solution;
  EXPECT_EQ(solution.maxSubArrayLen(vec, 1), 2);
}

TEST(NumArray, maxSubArrayLen3) {
  int a[] = {1,-1,0};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  Solution solution;
  EXPECT_EQ(solution.maxSubArrayLen(vec, 0), 3);
}

TEST(NumArray, maxSubArrayLen4) {
  int a[] = {0,0,0,0,0,0,0,0,0,0};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  Solution solution;
  EXPECT_EQ(solution.maxSubArrayLen(vec, 0), 10);
}

