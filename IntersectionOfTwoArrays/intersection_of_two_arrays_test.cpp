/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/19
 *
 * Source : https://leetcode-cn.com/problems/intersection-of-two-arrays/
 * Problem: Intersection of Two Arrays
 *               
 */
#include <gtest/gtest.h>
#include "intersection_of_two_arrays.h"

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
  int c[] = {2};
  vector<int> v1(a, a + sizeof(a)/sizeof(a[0]));
  vector<int> v2(b, b + sizeof(b)/sizeof(b[0]));
  vector<int> v3 = solution_.intersection(v1, v2);
  EXPECT_EQ(v3.size(), sizeof(c)/sizeof(c[0]));
  for (size_t i = 0; i < v3.size(); ++i) {
    EXPECT_EQ(v3[i], b[i]);
  }
}

