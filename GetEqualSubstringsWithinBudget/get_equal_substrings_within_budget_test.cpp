/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/05
 *
 * Source : https://leetcode-cn.com/problems/get-equal-substrings-within-budget/
 * Problem: Get Equal Substrings Within Budget
 *               
 */
#include <gtest/gtest.h>
#include "get_equal_substrings_within_budget.h"

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
    string s;
    string t;
    int cost;
    int len;
  };
  TestData test_data[] = {
    {"abcd", "bcdf", 3, 3},
    {"abcd", "cdef", 3, 1},
    {"abcd", "acde", 0, 1},
    {"krrgw", "zjxss", 19, 2},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_EQ(solution_.equalSubstring(test_data[i].s, test_data[i].t, test_data[i].cost), test_data[i].len);
  }
}

