/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/10
 *
 * Source : https://leetcode-cn.com/problems/decode-xored-array/
 * Problem: Decode XORed Array
 *               
 */
#include <gtest/gtest.h>
#include "decode_xored_array.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,2,3};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  vector<int> dec = solution_.decode(vec, 1);
  int b[] = {1,0,2,1};
  EXPECT_EQ(dec.size(), sizeof(b)/sizeof(b[0]));
  for (size_t i = 0; i < dec.size(); ++i) {
    EXPECT_EQ(dec[i], b[i]);
  }
}

