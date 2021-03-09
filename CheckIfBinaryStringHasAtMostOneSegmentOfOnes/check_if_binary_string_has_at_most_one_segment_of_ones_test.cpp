/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/09
 *
 * Source : https://leetcode-cn.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
 * Problem: Check if Binary String Has at Most One Segment of Ones
 *               
 */
#include <gtest/gtest.h>
#include "check_if_binary_string_has_at_most_one_segment_of_ones.h"

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
    bool one_seg;
  };
  TestData test_data[] = {
    {"1001", false},
    {"110", true},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_TRUE(solution_.checkOnesSegment(test_data[i].s) == test_data[i].one_seg);
  }
}

