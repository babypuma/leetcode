/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/19
 *
 * Source : https://leetcode-cn.com/problems/masking-personal-information/
 * Problem:	Masking Personal Information
 *
 */
#include <gtest/gtest.h>
#include "masking_personal_information.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, maskPII) {
  struct TestData {
    string info;
    string masked;
  };
  TestData test_data[] = {
    {"LeetCode@LeetCode.com", "l*****e@leetcode.com"},
    {"AB@qq.com", "a*****b@qq.com"},
    {"1(234)567-890", "***-***-7890"},
    {"86-(10)12345678", "+**-***-***-5678"},
    {"(98978)04-826-543", "+***-***-***-6543"},
  };
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    string s = solution_.maskPII(test_data[i].info);
    EXPECT_STREQ(s.c_str(), test_data[i].masked.c_str());
  }
}

