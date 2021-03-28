/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/28
 *
 * Source : https://leetcode-cn.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/
 * Problem: Minimum Number of Operations to Reinitialize a Permutation
 *               
 */
#include <gtest/gtest.h>
#include "minimum_number_of_operations_to_reinitialize_a_permutation.h"

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
    int n;
    int s;
  };
  TestData test_data[] = {
    {2, 1},
    {4, 2},
    {6, 4},
    {8, 3},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_EQ(solution_.reinitializePermutation(test_data[i].n), test_data[i].s);
  }
}

