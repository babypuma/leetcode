/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/14
 *
 * Source : https://leetcode-cn.com/problems/minimum-remove-to-make-valid-parentheses/
 * Problem: Minimum Remove to Make Valid Parentheses
 *               
 */
#include <gtest/gtest.h>
#include "minimum_remove_to_make_valid_parentheses.h"

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
    {"lee(t(c)o)de)", "lee(t(c)o)de"},
    {"a)b(c)d", "ab(c)d"},
    {"))((", ""},
    {"(a(b(c)d)", "a(b(c)d)"},
  };

  for (int i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_STREQ(solution_.minRemoveToMakeValid(test_data[i].n1).c_str(), test_data[i].n2.c_str());
  }
}

