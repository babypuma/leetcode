/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/11
 *
 * Source : https://leetcode-cn.com/problems/permutation-in-string/
 * Problem: Permutation in String
 *               
 */
#include <gtest/gtest.h>
#include "permutation_in_string.h"

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
    bool res;
  };
  TestData test_data[] = {
    {"ab", "eidbaooo", true},
    {"ab", "eidboaoo", false},
    {"ky", "ainwkckifykxlribaypk", true},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_TRUE(solution_.checkInclusion(test_data[i].s1, test_data[i].s2)  == test_data[i].res);
  }
}

