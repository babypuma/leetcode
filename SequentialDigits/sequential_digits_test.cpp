/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/01
 *
 * Source : https://leetcode.com/problems/sequential-digits/
 * Problem:	Sequential Digits
 *
 */
#include <gtest/gtest.h>
#include "sequential_digits.h"

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
    int low;
    int high;
    size_t sz;
  };
  TestData test_data[] = {
    {100, 300, 2},
    {1000, 13000, 7},
  };
  for (size_t i = 0; i < sizeof(test_data) / sizeof(test_data[0]); ++i) {
    vector<int> vec = solution_.sequentialDigits(test_data[i].low, test_data[i].high);
    EXPECT_EQ(vec.size(), test_data[i].sz);
  } 
}

