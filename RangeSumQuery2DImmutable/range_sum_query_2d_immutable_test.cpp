/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/29
 *
 * Source : https://leetcode-cn.com/problems/range-sum-query-2d-immutable/
 * Problem:	Range Sum Query 2D - Immutable
 *
 */
#include <gtest/gtest.h>
#include "range_sum_query_2d_immutable.h"

TEST(NumMatrix, sumRegion) {
  int init[][5] = {
    {3, 0, 1, 4, 2},
    {5, 6, 3, 2, 1},
    {1, 2, 0, 1, 5},
    {4, 1, 0, 1, 7},
    {1, 0, 3, 0, 5},
  };
  vector<vector<int> > matrix;
  for (size_t i = 0; i < 5; ++i) {
    vector<int> vec;
    for (size_t j = 0; j < 5; ++j) {
      vec.push_back(init[i][j]);
    }
    matrix.push_back(vec);
  }
  struct TestData {
    int r1;
    int c1;
    int r2;
    int c2;
    int sum;
  };
  TestData test_data[] = {
    {2, 1, 4, 3, 8},
    {1, 1, 2, 2, 11},
    {1, 2, 2, 4, 12},
  };
  NumMatrix num_matrix(matrix);
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_EQ(num_matrix.sumRegion(test_data[i].r1, test_data[i].c1, test_data[i].r2, test_data[i].c2), test_data[i].sum);
  }
}

