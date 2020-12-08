/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/12
 * Update : 2020/12/08
 *
 * Source : https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
 * Problem:	Search in Rotated Sorted Array 
 *
 */
#include <gtest/gtest.h>
#include "search_in_rotated_sorted_array.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {4, 5, 6, 7, 0, 1, 2};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(vec.size(), sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.search(vec, 4), 0);
  EXPECT_EQ(solution_.search(vec, 2), 6);
  EXPECT_EQ(solution_.search(vec, 7), 3);
  EXPECT_EQ(solution_.search(vec, 0), 4);
  EXPECT_EQ(solution_.search(vec, 8), -1);
  EXPECT_EQ(solution_.search(vec, -1), -1);
}

TEST_F(SolutionTest, case2) {
  int a[] = {1, 3};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(vec.size(), sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.search(vec, 3), 1);
  EXPECT_EQ(solution_.search(vec, 1), 0);
  EXPECT_EQ(solution_.search(vec, 2), -1);
}

TEST_F(SolutionTest, case3) {
  int a[] = {3, 1};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(vec.size(), sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.search(vec, 1), 1);
}

