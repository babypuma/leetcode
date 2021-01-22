/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/22
 *
 * Source : https://leetcode-cn.com/problems/tuple-with-same-product/
 * Problem: Tuple with Same Product
 *               
 */
#include <gtest/gtest.h>
#include "tuple_with_same_product.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {2,3,4,6,8,12};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.tupleSameProduct(vec), 40);
}

TEST_F(SolutionTest, case2) {
  int a[] = {2,3,5,7};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.tupleSameProduct(vec), 0);
}

TEST_F(SolutionTest, case3) {
  int a[] = {2,3,4,6};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.tupleSameProduct(vec), 8);
}

