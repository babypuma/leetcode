/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/19
 *
 * Source : https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/
 * Problem: Intersection of Two Arrays II
 *               
 */
#include <gtest/gtest.h>
#include "intersection_of_two_arrays_ii.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,2,2,1};
  int b[] = {2, 2};
  int c[] = {2, 2};
  vector<int> v1(a, a + sizeof(a)/sizeof(a[0]));
  vector<int> v2(b, b + sizeof(b)/sizeof(b[0]));
  vector<int> v3 = solution_.intersect(v1, v2);
  EXPECT_EQ(v3.size(), sizeof(c)/sizeof(c[0]));
  for (size_t i = 0; i < v3.size(); ++i) {
    EXPECT_EQ(v3[i], b[i]);
  }
}

TEST_F(SolutionTest, case2) {
  int a[] = {4,9,5};
  int b[] = {9,4,9,8,4};
  int c[] = {4,9};
  vector<int> v1(a, a + sizeof(a)/sizeof(a[0]));
  vector<int> v2(b, b + sizeof(b)/sizeof(b[0]));
  vector<int> v3 = solution_.intersect(v1, v2);
  EXPECT_EQ(v3.size(), sizeof(c)/sizeof(c[0]));
  for (size_t i = 0; i < v3.size(); ++i) {
    EXPECT_EQ(v3[i], b[i]);
  }
}

