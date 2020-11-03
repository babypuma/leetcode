/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/11/04
 *
 * Source : https://leetcode-cn.com/problems/contiguous-array/
 * Problem:	Contiguous Array
 *
 */
#include <gtest/gtest.h>
#include "contiguous_array.h"

TEST(NumArray, findMaxLength) {
  int a[] = {0, 1};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  Solution solution;
  EXPECT_EQ(solution.findMaxLength(vec), 2);
}

TEST(NumArray, findMaxLength2) {
  int a[] = {0,1,0};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  Solution solution;
  EXPECT_EQ(solution.findMaxLength(vec), 2);
}

TEST(NumArray, findMaxLength3) {
  int a[] = {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  Solution solution;
  EXPECT_EQ(solution.findMaxLength(vec), 12);
}

