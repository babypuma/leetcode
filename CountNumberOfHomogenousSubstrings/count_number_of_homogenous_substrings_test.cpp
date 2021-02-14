/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/14
 *
 * Source : https://leetcode-cn.com/problems/count-number-of-homogenous-substrings/
 * Problem: Count Number of Homogenous Substrings
 *               
 */
#include <gtest/gtest.h>
#include "count_number_of_homogenous_substrings.h"

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
    string s;
    int n;
  };
  TestData test_data[] = {
    {"abbcccaa", 13},
    {"xy", 2},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_EQ(solution_.countHomogenous(test_data[i].s), test_data[i].n);
  }
}

