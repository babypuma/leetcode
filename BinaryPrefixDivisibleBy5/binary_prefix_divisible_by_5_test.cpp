/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/14
 *
 * Source : https://leetcode-cn.com/problems/binary-prefix-divisible-by-5/
 * Problem: Binary Prefix Divisible By 5
 *               
 */
#include <gtest/gtest.h>
#include "binary_prefix_divisible_by_5.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {0,1,1,1,1,1};
  bool b[] = {true,false,false,false,true,false};
  vector<int> in(a, a + sizeof(a) / sizeof(a[0]));
  vector<bool> out = solution_.prefixesDivBy5(in);
  EXPECT_EQ(out.size(), sizeof(b) / sizeof(b[0]));
  for (size_t i = 0; i < out.size(); ++i) {
    EXPECT_EQ(out[i], b[i]);
  }
}

