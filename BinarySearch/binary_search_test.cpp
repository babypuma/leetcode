/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/11
 *
 * Source : https://leetcode-cn.com/problems/binary-search/
 * Problem: Binary Search
 *               
 */
#include <gtest/gtest.h>
#include "binary_search.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {-1,0,3,5,9,12};
  vector<int> nums(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.search(nums, 9), 4);
}

