/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/14
 *
 * Source : https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 * Problem: Median of Two Sorted Arrays
 *               
 */
#include <gtest/gtest.h>
#include "sliding_window_maximum.h"

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
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  vector<int> window = solution_.maxSlidingWindow(vec, 3);

  int b[] = {3,3,5,5,6,7};
  EXPECT_EQ(window.size(), sizeof(b)/sizeof(b[0]));
  for (size_t i = 0; i < sizeof(b)/sizeof(b[0]); ++i) {
    EXPECT_EQ(b[i], window[i]);
  }
}

TEST_F(SolutionTest, case2) {
  int a[] = {1,-1};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  vector<int> window = solution_.maxSlidingWindow(vec, 1);

  int b[] = {1,-1};
  EXPECT_EQ(window.size(), sizeof(b)/sizeof(b[0]));
  for (size_t i = 0; i < sizeof(b)/sizeof(b[0]); ++i) {
    EXPECT_EQ(b[i], window[i]);
  }
}

TEST_F(SolutionTest, case3) {
  int a[] = {1,3,1,2,0,5};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  vector<int> window = solution_.maxSlidingWindow(vec, 3);

  int b[] = {3,3,2,5};
  EXPECT_EQ(window.size(), sizeof(b)/sizeof(b[0]));
  for (size_t i = 0; i < sizeof(b)/sizeof(b[0]); ++i) {
    EXPECT_EQ(b[i], window[i]);
  }
}

TEST_F(SolutionTest, case4) {
  int a[] = {9,10,9,-7,-4,-8,2,-6};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  vector<int> window = solution_.maxSlidingWindow(vec, 5);

  int b[] = {10,10,9,2};
  EXPECT_EQ(window.size(), sizeof(b)/sizeof(b[0]));
  for (size_t i = 0; i < sizeof(b)/sizeof(b[0]); ++i) {
    EXPECT_EQ(b[i], window[i]);
  }
}

