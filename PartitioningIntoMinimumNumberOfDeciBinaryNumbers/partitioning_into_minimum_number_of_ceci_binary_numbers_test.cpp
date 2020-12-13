/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/13
 *
 * Source : https://leetcode-cn.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
 * Problem:	Partitioning Into Minimum Number Of Deci-Binary Numbers
 *               
 */
#include <gtest/gtest.h>
#include "partitioning_into_minimum_number_of_ceci_binary_numbers.h"

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
    string str;
    int n;
  };
  TestData test_data[] = {
    {"27346209830709182346", 9},
    {"82734", 8},
    {"32", 3},
    {"1", 1},
    {"1111111", 1},
  };

  for (int i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_EQ(solution_.minPartitions(test_data[i].str), test_data[i].n);
  }
}

