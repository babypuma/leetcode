/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/22
 *
 * Source : https://leetcode-cn.com/problems/add-to-array-form-of-integer/
 * Problem: Add to Array-Form of Integer
 *               
 */
#include <gtest/gtest.h>
#include "add_to_array_form_of_integer.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,2,0,0};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  vector<int> v =  solution_.addToArrayForm(vec, 34);
  int b[] = {1,2,3,4};
  EXPECT_EQ(v.size(),  sizeof(b)/sizeof(b[0]));
  for (size_t i = 0; i < v.size(); ++i) {
    EXPECT_EQ(v[i], b[i]);
  }
}

TEST_F(SolutionTest, case2) {
  int a[] = {9,9,9,9,9,9,9,9,9,9};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  vector<int> v =  solution_.addToArrayForm(vec, 1);
  int b[] = {1,0,0,0,0,0,0,0,0,0,0};
  EXPECT_EQ(v.size(),  sizeof(b)/sizeof(b[0]));
  for (size_t i = 0; i < v.size(); ++i) {
    EXPECT_EQ(v[i], b[i]);
  }
}

