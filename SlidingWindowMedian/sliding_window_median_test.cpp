/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/03
 *
 * Source : https://leetcode-cn.com/problems/sliding-window-median/
 * Problem: Sliding Window Median
 *               
 */
#include <gtest/gtest.h>
#include "sliding_window_median.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,3,-1,-3,5,3,6,7};
  vector<int> w(a, a + sizeof(a)/sizeof(a[0]));
  vector<double> m = solution_.medianSlidingWindow(w, 3);

  double b[] = {1,-1,-1,3,5,6};
  EXPECT_EQ(sizeof(b)/sizeof(b[0]), m.size());
  for (size_t i = 0; i < sizeof(b)/sizeof(b[0]); ++i) {
    EXPECT_EQ(b[i], m[i]);
  }
}

TEST_F(SolutionTest, case2) {
  int a[] = {5,5,8,1,4,7,1,3,8,4};
  vector<int> w(a, a + sizeof(a)/sizeof(a[0]));
  vector<double> m = solution_.medianSlidingWindow(w, 8);

  double b[] = {4.5,4.5,4.0};
  EXPECT_EQ(sizeof(b)/sizeof(b[0]), m.size());
  for (size_t i = 0; i < sizeof(b)/sizeof(b[0]); ++i) {
    EXPECT_EQ(b[i], m[i]);
  }
}

