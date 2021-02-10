/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/09
 *
 * Source : https://leetcode-cn.com/problems/subarrays-with-k-different-integers/
 * Problem: Subarrays with K Different Integers
 *               
 */
#include <gtest/gtest.h>
#include "subarray_with_k_different_integers.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,2,1,2,3};
  vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
  EXPECT_EQ(solution_.subarraysWithKDistinct(v, 2), 7);
}

TEST_F(SolutionTest, case2) {
  int a[] = {1,2,1,3,4};
  vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
  EXPECT_EQ(solution_.subarraysWithKDistinct(v, 3), 3);
}

