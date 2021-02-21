/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/21
 *
 * Source : https://leetcode-cn.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
 * Problem: Minimum Number of Operations to Move All Balls to Each Box
 *               
 */
#include <gtest/gtest.h>
#include "minimum_number_of_operations_to_move_all_balls_to_each_box.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  vector<int> ops = solution_.minOperations("110");
  int a[] = {1,1,3};
  EXPECT_EQ(ops.size(), sizeof(a)/sizeof(a[0]));
  for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
    EXPECT_EQ(a[i], ops[i]);
  }
}

TEST_F(SolutionTest, case2) {
  vector<int> ops = solution_.minOperations("001011");
  int a[] = {11,8,5,4,3,4};
  EXPECT_EQ(ops.size(), sizeof(a)/sizeof(a[0]));
  for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
    EXPECT_EQ(a[i], ops[i]);
  }
}

