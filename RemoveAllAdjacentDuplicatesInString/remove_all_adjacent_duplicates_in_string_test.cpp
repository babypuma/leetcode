/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/09
 *
 * Source : https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/
 * Problem: Remove All Adjacent Duplicates In String
 *               
 */
#include <gtest/gtest.h>
#include "remove_all_adjacent_duplicates_in_string.h"

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
  };
  TestData test_data[] = {
    {"abbaca", "ca"},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_STREQ(solution_.removeDuplicates(test_data[i].s1).c_str(), test_data[i].s2.c_str());
  }
}

