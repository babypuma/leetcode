/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/12
 *
 * Source : https://leetcode-cn.com/problems/non-decreasing-array/
 * Problem: Non-decreasing Array
 *               
 */
#include <gtest/gtest.h>
#include "non_decreasing_array.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {4,2,3};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_TRUE(solution_.checkPossibility(vec));
}

TEST_F(SolutionTest, case2) {
  int a[] = {4,2,1};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_FALSE(solution_.checkPossibility(vec));
}

TEST_F(SolutionTest, case3) {
  int a[] = {3,4,2,3};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_FALSE(solution_.checkPossibility(vec));
}

TEST_F(SolutionTest, case4) {
  int a[] = {5,7,1,8};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_TRUE(solution_.checkPossibility(vec));
}

TEST_F(SolutionTest, case5) {
  int a[] = {4,2,3};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_TRUE(solution_.checkPossibility(vec));
}

