/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/11/06
 *
 * Source : https://leetcode-cn.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
 * Problem:	Find Two Non-overlapping Sub-arrays Each With Target Sum
 *
 */
#include <gtest/gtest.h>
#include "find_two_non_overlapping_subarrays_each_with_target_sum.h"

TEST(SolutionTest, minSumOfLengths) {
  int a[] = {3,2,2,4,3};
  vector<int> vec(a, a + sizeof(a) / sizeof(a[0]));
  Solution solution;
  EXPECT_EQ(solution.minSumOfLengths(vec, 3), 2);
}

TEST(SolutionTest, minSumOfLengths2) {
  int a[] = {4,3,2,6,2,3,4};
  vector<int> vec(a, a + sizeof(a) / sizeof(a[0]));
  Solution solution;
  EXPECT_EQ(solution.minSumOfLengths(vec, 6), -1);
}

TEST(SolutionTest, minSumOfLengths3) {
  int a[] = {3,1,1,1,5,1,2,1};
  vector<int> vec(a, a + sizeof(a) / sizeof(a[0]));
  Solution solution;
  EXPECT_EQ(solution.minSumOfLengths(vec, 3), 3);
}

TEST(SolutionTest, minSumOfLengths4) {
  int a[] = {1,6,1};
  vector<int> vec(a, a + sizeof(a) / sizeof(a[0]));
  Solution solution;
  EXPECT_EQ(solution.minSumOfLengths(vec, 7), -1);
}

