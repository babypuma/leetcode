/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/08/31
 * Update : 2020/12/07
 *
 * Source : https://leetcode-cn.com/problems/container-with-most-water/
 * Problem:	Container With Most Water
 *               
 */
#include <gtest/gtest.h>
#include "container_with_most_water.h"

TEST(SolutionTest, maxArea) {
  int test_data[] = {1,8,6,2,5,4,8,3,7};
  vector<int> vec;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    vec.push_back(test_data[i]);
  }
  Solution solution;
  EXPECT_EQ(solution.maxArea(vec), 49);
}
