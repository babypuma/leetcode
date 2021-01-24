/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/24
 *
 * Source : https://leetcode-cn.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/
 * Problem: Change Minimum Characters to Satisfy One of Three Conditions
 *               
 */
#include <gtest/gtest.h>
#include "change_minimum_characters_to_satisfy_one_of_three_conditions.h"

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
    int c;
  };
  TestData test_data[] = {
    {"dabadd", "cda", 3},
    {"aba", "caa", 2},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_EQ(solution_.minCharacters(test_data[i].n1, test_data[i].n2), test_data[i].c);
  }
}

