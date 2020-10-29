/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/29
 *
 * Source : https://leetcode-cn.com/problems/range-sum-query-immutable/
 * Problem:	Range Sum Query - Immutable
 *
 */
#include <gtest/gtest.h>
#include "range_sum_query_immutable.h"

TEST(NumArray, sumRange) {
  struct TestData {
    int i;
    int j;
    int sum;
  };
  TestData test_data[] = {
    {0, 2, 1},
    {2, 5, -1},
    {0, 5, -3},
  };
  int a[] = {-2, 0, 3, -5, 2, -1};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  NumArray num_array(vec);
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_EQ(num_array.sumRange(test_data[i].i, test_data[i].j), test_data[i].sum);
  }
}

