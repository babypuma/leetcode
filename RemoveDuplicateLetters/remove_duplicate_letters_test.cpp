/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/29
 *
 * Source : https://leetcode-cn.com/problems/remove-duplicate-letters/
 * Problem: Remove Duplicate Letters
 *               
 */
#include <gtest/gtest.h>
#include "remove_duplicate_letters.h"

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
    string n1;
    string n2;
  };
  TestData test_data[] = {
    {"bcabc", "abc"},
    {"cbacdcbc", "acdb"},
    {"bbcaac", "bac"},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_STREQ(solution_.removeDuplicateLetters(test_data[i].n1).c_str(), test_data[i].n2.c_str());
  }
}

