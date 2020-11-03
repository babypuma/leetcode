/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/11/02
 *
 * Source : https://leetcode-cn.com/problems/subarray-sum-equals-k/
 * Problem:	Subarray Sum Equals K
 *
 */
#include <gtest/gtest.h>
#include "subarray_sum_equals_k.h"

TEST(NumArray, subarraySum) {
  int a[] = {1,2,3};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  Solution solution;
  EXPECT_EQ(solution.subarraySum(vec, 3), 2);
}

TEST(NumArray, subarraySum2) {
  int a[] = {1,1,1};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  Solution solution;
  EXPECT_EQ(solution.subarraySum(vec, 2), 2);
}

TEST(NumArray, subarraySum3) {
  int a[] = {1,-1,0};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  Solution solution;
  EXPECT_EQ(solution.subarraySum(vec, 0), 3);
}

TEST(NumArray, subarraySum4) {
  int a[] = {0,0,0,0,0,0,0,0,0,0};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  Solution solution;
  EXPECT_EQ(solution.subarraySum(vec, 0), 55);
}

