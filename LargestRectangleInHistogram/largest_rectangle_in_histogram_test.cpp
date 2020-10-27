/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/27
 *
 * Source : https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
 * Problem:	Largest Rectangle in Histogram
 *
 */
#include <gtest/gtest.h>
#include "largest_rectangle_in_histogram.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, largestRectangleArea) {
  int a[] = {2,1,5,6,2,3};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.largestRectangleArea(vec), 10);
}

TEST_F(SolutionTest, largestRectangleArea2) {
  int a[] = {1,2,2};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.largestRectangleArea(vec), 4);
}

TEST_F(SolutionTest, largestRectangleArea3) {
  int a[] = {5,4,1,2};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.largestRectangleArea(vec), 8);
}

TEST_F(SolutionTest, largestRectangleArea4) {
  int a[] = {4,2,0,3,2,5};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.largestRectangleArea(vec), 6);
}

