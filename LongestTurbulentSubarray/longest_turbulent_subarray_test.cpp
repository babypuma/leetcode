/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/08
 *
 * Source : https://leetcode-cn.com/problems/longest-turbulent-subarray/
 * Problem: Longest Turbulent Subarray
 *               
 */
#include <gtest/gtest.h>
#include "longest_turbulent_subarray.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {9,4,2,10,7,8,8,1,9};
  vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.maxTurbulenceSize(arr), 5);
}

TEST_F(SolutionTest, case2) {
  int a[] = {4,8,12,16};
  vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.maxTurbulenceSize(arr), 2);
}

TEST_F(SolutionTest, case3) {
  int a[] = {9};
  vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.maxTurbulenceSize(arr), 1);
}

TEST_F(SolutionTest, case4) {
  int a[] = {4,2,10,7,8};
  vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.maxTurbulenceSize(arr), 5);
}

TEST_F(SolutionTest, case5) {
  int a[] = {4,4};
  vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.maxTurbulenceSize(arr), 1);
}

TEST_F(SolutionTest, case6) {
  int a[] = {8,8,9,10,6,8,2,4,2,2,10,6,6,10,10,2,3,5,1,2,10,4,2,0,9,4,9,3,0,6,3,2,3,10,10,6,4,6,4,4,2,5,1,4,1,1,9,8,9,5,3,5,5,4,5,5,6,5,3,3,7,2,0,10,9,7,7,3,5,1,0,9,6,3,1,3,4,4,3,6,3,2,1,4,10,2,3,4,4,3,6,7,6,2,1,7,0,6,8,10};
  vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.maxTurbulenceSize(arr), 7);
}

