/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/20
 *
 * Source : https://leetcode-cn.com/problems/maximum-product-of-three-numbers/
 * Problem: Maximum Product of Three Numbers
 *               
 */
#include <gtest/gtest.h>
#include "maximum_product_of_three_numbers.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,2,3,4};
  vector<int> vec(a, a + sizeof(a) / sizeof(a[0]));
  EXPECT_EQ(solution_.maximumProduct(vec), 24);
}

