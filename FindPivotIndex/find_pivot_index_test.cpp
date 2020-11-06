/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/11/06
 *
 * Source : https://leetcode-cn.com/problems/find-pivot-index/
 * Problem:	Find Pivot Index
 *
 */
#include <gtest/gtest.h>
#include "find_pivot_index.h"

TEST(SolutionTest, pivotIndex) {
  int a[] = {1,7,3,6,5,6};
  vector<int> vec(a, a + sizeof(a) / sizeof(int));
  Solution solution;
  EXPECT_EQ(solution.pivotIndex(vec), 3);
}

TEST(SolutionTest, pivotIndex2) {
  int a[] = {1,2,3};
  vector<int> vec(a, a + sizeof(a) / sizeof(int));
  Solution solution;
  EXPECT_EQ(solution.pivotIndex(vec), -1);
}

