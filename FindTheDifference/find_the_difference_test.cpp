/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/18
 *
 * Source : https://leetcode-cn.com/problems/find-the-difference/
 * Problem: Find the Difference
 *               
 */
#include <gtest/gtest.h>
#include "find_the_difference.h"

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
    char diff;
  };
  TestData test_data[] = {
    {"abcd", "abcde", 'e'},
    {"", "y", 'y'},
    {"a", "aa", 'a'},
    {"ae", "aea", 'a'},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_EQ(solution_.findTheDifference(test_data[i].s, test_data[i].t), test_data[i].diff);
  }
}

