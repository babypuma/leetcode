/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/11/04
 *
 * Source : https://leetcode-cn.com/problems/count-number-of-nice-subarrays/
 * Problem:	Count Number of Nice Subarrays
 *
 */
#include <gtest/gtest.h>
#include "count_number_of_nice_subarrays.h"

TEST(NumArray, numberOfSubarrays) {
  int a[] = {1,1,2,1,1};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  Solution solution;
  EXPECT_EQ(solution.numberOfSubarrays(vec, 3), 2);
}

TEST(NumArray, numberOfSubarrays2) {
  int a[] = {2,4,6};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  Solution solution;
  EXPECT_EQ(solution.numberOfSubarrays(vec, 1), 0);
}

TEST(NumArray, numberOfSubarrays3) {
  int a[] = {2,2,2,1,2,2,1,2,2,2};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  Solution solution;
  EXPECT_EQ(solution.numberOfSubarrays(vec, 2), 16);
}

