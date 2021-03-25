/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/25
 *
 * Source : https://leetcode-cn.com/problems/valid-mountain-array/
 * Problem: Valid Mountain Array
 *               
 */
#include <gtest/gtest.h>
#include "valid_mountain_array.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {0,3,2,1};
  vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_TRUE(solution_.validMountainArray(arr));
}

TEST_F(SolutionTest, case2) {
  int a[] = {3,5,5};
  vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_FALSE(solution_.validMountainArray(arr));
}

