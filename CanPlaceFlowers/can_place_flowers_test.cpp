/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/01
 *
 * Source : https://leetcode-cn.com/problems/can-place-flowers/
 * Problem: Can Place Flowers
 *               
 */
#include <gtest/gtest.h>
#include "can_place_flowers.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,0,0,0,1};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_TRUE(solution_.canPlaceFlowers(vec, 1));
  EXPECT_FALSE(solution_.canPlaceFlowers(vec, 2));
}

