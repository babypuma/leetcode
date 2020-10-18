/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/18
 *
 * Source : https://leetcode-cn.com/problems/minimum-ascii-delete-sum-for-two-strings/
 * Problem:	Minimum ASCII Delete Sum for Two Strings
 *
 */
#include <gtest/gtest.h>
#include "minimum_ascii_delete_sum_for_two_strings.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, minimumDeleteSum) {
  struct TestData {
    string str1;
    string str2;
    int mini_sum;
  };
  TestData test_data[] = {
    {"sea", "eat", 231},
    {"delete", "leet", 403},
  };
  for (size_t i = 0; i < sizeof(test_data) / sizeof(test_data[0]); ++i) {
    int sum = solution_.minimumDeleteSum(test_data[i].str1, test_data[i].str2);
    EXPECT_EQ(sum, test_data[i].mini_sum);
  } 
}

