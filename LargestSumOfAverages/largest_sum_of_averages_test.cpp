/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/15
 *
 * Source : https://leetcode-cn.com/problems/largest-sum-of-averages/
 * Problem:	Largest Sum of Averages
 *
 */
#include <gtest/gtest.h>
#include "largest_sum_of_averages.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, largestSumOfAverages1) {
  int a[] = {9,1,2,3,9};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  double sum = solution_.largestSumOfAverages(vec, 3);
  EXPECT_DOUBLE_EQ(sum, 20);
}

TEST_F(SolutionTest, largestSumOfAverages2) {
  int a[] = {1,2,3,4,5,6,7};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  double sum = solution_.largestSumOfAverages(vec, 4);
  EXPECT_DOUBLE_EQ(sum, 20.5);
}

