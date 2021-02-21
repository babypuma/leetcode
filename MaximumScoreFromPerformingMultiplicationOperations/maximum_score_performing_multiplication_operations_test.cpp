/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/21
 *
 * Source : https://leetcode-cn.com/problems/maximum-score-from-performing-multiplication-operations/
 * Problem: Maximum Score from Performing Multiplication Operations
 *               
 */
#include <gtest/gtest.h>
#include "maximum_score_performing_multiplication_operations.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,2,3};
  vector<int> nums(a, a + sizeof(a) / sizeof(a[0]));
  int b[] = {3,2,1};
  vector<int> mul(b, b + sizeof(b) / sizeof(b[0]));
  EXPECT_EQ(solution_.maximumScore(nums, mul), 14);
}

TEST_F(SolutionTest, case2) {
  int a[] = {-5,-3,-3,-2,7,1};
  vector<int> nums(a, a + sizeof(a) / sizeof(a[0]));
  int b[] = {-10,-5,3,4,6};
  vector<int> mul(b, b + sizeof(b) / sizeof(b[0]));
  EXPECT_EQ(solution_.maximumScore(nums, mul), 102);
}

