/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/11
 *
 * Source : https://leetcode-cn.com/problems/add-strings/
 * Problem:	Add Strings
 *               
 */
#include <gtest/gtest.h>
#include "add_strings.h"

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
    string n;
  };
  TestData test_data[] = {
    {"0", "0", "0"},
    {"123", "98", "221"},
    {"0", "98", "98"},
  };

  for (int i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_STREQ(solution_.addStrings(test_data[i].n1, test_data[i].n2).c_str(), test_data[i].n.c_str());
  }
}

