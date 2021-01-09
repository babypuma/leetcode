/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/09
 *
 * Source : https://leetcode-cn.com/problems/count-and-say/
 * Problem: Count and Say
 *               
 */
#include <gtest/gtest.h>
#include "count_and_say.h"

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
    int n;
    string str;
  };
  TestData test_data[] = {
    {1, "1"},
    {4, "1211"},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_STREQ(solution_.countAndSay(test_data[i].n).c_str(), test_data[i].str.c_str());
  }
}

