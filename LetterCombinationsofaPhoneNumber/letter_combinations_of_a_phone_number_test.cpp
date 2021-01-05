/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/06/30
 * Update : 2021/01/05
 *
 * Source : https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
 * Problem: Letter Combinations of a Phone Number
 *
 */
#include <gtest/gtest.h>
#include "letter_combinations_of_a_phone_number.h"

using std::set;

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  vector<string> vec;
  vec = solution_.letterCombinations(string("23"));
  EXPECT_EQ((int)vec.size(), 9);

  char *chars[] = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
  for (size_t i = 0; i < sizeof(chars)/sizeof(char *); i++) {
    EXPECT_TRUE(find(vec.begin(), vec.end(), string(chars[i])) != vec.end());
  }
}

TEST_F(SolutionTest, case2) {
  vector<string> vec;
  vec = solution_.letterCombinations(string(""));
  EXPECT_EQ((int)vec.size(), 0);
}

TEST_F(SolutionTest, case3) {
  vector<string> vec;
  vec = solution_.letterCombinations(string("2"));
  EXPECT_EQ((int)vec.size(), 3);

  char *chars[] = {"a", "b", "c"};
  for (size_t i = 0; i < sizeof(chars)/sizeof(char *); i++) {
    EXPECT_TRUE(find(vec.begin(), vec.end(), string(chars[i])) != vec.end());
  }
}

