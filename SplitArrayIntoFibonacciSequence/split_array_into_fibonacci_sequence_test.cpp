/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/08/31
 *
 * Source : https://leetcode.com/problems/split-array-into-fibonacci-sequence/
 * Problem:	Split Array into Fibonacci Sequence
 *
 */
#include <gtest/gtest.h>
#include "split_array_into_fibonacci_sequence.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, splitIntoFibonacci) {
  struct TestData {
    string str;
    size_t sz;
  };
  TestData test_data[] = {
    {"123456579", 3},
    {"11235813", 7},
    {"112358130", 0},
    {"0123", 0},
    {"1101111", 4},
    {"1011", 4},
    {"5511816597", 0},
    {"214748364721474836422147483641", 0},
  };
  for (size_t i = 0; i < sizeof(test_data) / sizeof(test_data[0]); ++i) {
    vector<int> vec = solution_.splitIntoFibonacci(test_data[i].str);
    EXPECT_EQ(vec.size(), test_data[i].sz);
  } 
}

