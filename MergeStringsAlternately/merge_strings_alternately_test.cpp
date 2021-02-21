/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/21
 *
 * Source : https://leetcode-cn.com/problems/merge-strings-alternately/
 * Problem: Merge Strings Alternately
 *               
 */
#include <gtest/gtest.h>
#include "merge_strings_alternately.h"

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
    string w1;
    string w2;
    string m;
  };
  TestData test_data[] = {
    {"abc", "pqr", "apbqcr"},
    {"ab", "pqrs", "apbqrs"},
    {"abcd", "pq", "apbqcd"},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_STREQ(solution_.mergeAlternately(test_data[i].w1, test_data[i].w2).c_str(), test_data[i].m.c_str());
  }
}

