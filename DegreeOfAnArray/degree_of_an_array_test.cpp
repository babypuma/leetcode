/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/20
 *
 * Source : https://leetcode-cn.com/problems/degree-of-an-array/
 * Problem: Degree of an Array
 *               
 */
#include <gtest/gtest.h>
#include "degree_of_an_array.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,2,2,3,1};
  vector<int> nums(a, a + sizeof(a) / sizeof(a[0]));
  EXPECT_EQ(solution_.findShortestSubArray(nums), 2);
}

TEST_F(SolutionTest, case2) {
  int a[] = {1,2,2,3,1,4,2};
  vector<int> nums(a, a + sizeof(a) / sizeof(a[0]));
  EXPECT_EQ(solution_.findShortestSubArray(nums), 6);
}

