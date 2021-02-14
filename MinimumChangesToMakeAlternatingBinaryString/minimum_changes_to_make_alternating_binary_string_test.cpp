/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/14
 *
 * Source : https://leetcode-cn.com/problems/minimum-changes-to-make-alternating-binary-string/
 * Problem: Minimum Changes To Make Alternating Binary String
 *               
 */
#include <gtest/gtest.h>
#include "minimum_changes_to_make_alternating_binary_string.h"

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
    int m;
  };
  TestData test_data[] = {
    {"0100", 1},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_EQ(solution_.minOperations(test_data[i].s), test_data[i].m);
  }
}

