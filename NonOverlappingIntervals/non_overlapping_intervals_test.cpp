/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/01
 *
 * Source : https://leetcode-cn.com/problems/non-overlapping-intervals/
 * Problem: Non-overlapping Intervals
 *               
 */
#include <gtest/gtest.h>
#include "non_overlapping_intervals.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  struct TestData {
    int begin;
    int end;
  };
  TestData test_data[] = {
    {1, 2},
    {2, 3},
    {3, 4},
    {1, 3},
  };

  vector<vector<int> > vec;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    vec.push_back(vector<int>());
    vec.back().push_back(test_data[i].begin);
    vec.back().push_back(test_data[i].end);
  }
  EXPECT_EQ(solution_.eraseOverlapIntervals(vec), 1);
}

