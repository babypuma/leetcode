/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/11
 *
 * Source : https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/
 * Problem: Kth Largest Element in a Stream
 *               
 */
#include <gtest/gtest.h>
#include "kth_largest_element_in_a_stream.h"

TEST(KthLargest, case1) {
  struct TestData {
    int val;
    int res;
  };
  TestData test_data[] = {
    {3,4},
    {5,5},
    {10,5},
    {9,8},
    {4,8},
  };
  int a[] = {4, 5, 8, 2};
  int k = 3;
  vector<int> nums(a, a + sizeof(a)/sizeof(a[0]));
  KthLargest solution_(k, nums);
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_EQ(solution_.add(test_data[i].val), test_data[i].res);
  }
}

