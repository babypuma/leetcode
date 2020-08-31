/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/08/31
 *
 * Source : https://leetcode.com/problems/additive-number/
 * Problem:	Additive Number
 *
 */
#include <gtest/gtest.h>
#include "additive_number.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, isAdditiveNumber) {
  struct TestData {
    string str;
    bool result;
  };
  TestData test_data[] = {
    {"112358", true},
    {"199100199", true},
    {"121474836472147483648", true},
  };
  for (size_t i = 0; i < sizeof(test_data) / sizeof(test_data[0]); ++i) {
    EXPECT_TRUE(solution_.isAdditiveNumber(test_data[i].str) == test_data[i].result);
  } 
}

