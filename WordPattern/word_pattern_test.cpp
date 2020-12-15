/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/16
 *
 * Source : https://leetcode-cn.com/problems/word-pattern/
 * Problem: Word Pattern
 *               
 */
#include <gtest/gtest.h>
#include "word_pattern.h"

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
    bool matched;
  };
  TestData test_data[] = {
    {"abba", "dog cat cat dog", true},
    {"abba", "dog cat cat fish", false},
    {"aaaa", "dog cat cat dog", false},
    {"abba", "dog dog dog dog", false},
    {"jquery", "jquery", false},
  };

  for (int i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_TRUE(solution_.wordPattern(test_data[i].n1, test_data[i].n2) == test_data[i].matched);
  }
}

