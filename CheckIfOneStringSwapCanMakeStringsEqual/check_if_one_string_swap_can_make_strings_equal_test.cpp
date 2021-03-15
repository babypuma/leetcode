/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/14
 *
 * Source : https://leetcode-cn.com/problems/check-if-one-string-swap-can-make-strings-equal/
 * Problem: Check if One String Swap Can Make Strings Equal
 *               
 */
#include <gtest/gtest.h>
#include "check_if_one_string_swap_can_make_strings_equal.h"

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
    string s1;
    string s2;
    bool equal;
  };
  TestData test_data[] = {
    {"bank", "kanb", true},
    {"attack", "defend", false},
    {"kelb", "kelb", true},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_TRUE(solution_.areAlmostEqual(test_data[i].s1, test_data[i].s2) == test_data[i].equal);
  }
}

