/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/10
 *
 * Source : https://leetcode-cn.com/problems/integer-to-english-words/
 * Problem:	Integer to English Words
 *               
 */
#include <gtest/gtest.h>
#include "integer_to_english_words.h"

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
    int num;
    string str;
  };
  TestData test_data[] = {
    {123, "One Hundred Twenty Three"},
    {12345, "Twelve Thousand Three Hundred Forty Five"},
    {1234567, "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"},
    {1234567891, "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"},
    {1000, "One Thousand"},
  };
  for (int i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_STREQ(solution_.numberToWords(test_data[i].num).c_str(), test_data[i].str.c_str());
  }
}

