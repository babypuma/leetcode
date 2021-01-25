/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/25
 *
 * Source : https://leetcode-cn.com/problems/decode-xored-permutation/
 * Problem: Decode XORed Permutation
 *               
 */
#include <gtest/gtest.h>
#include "decode_xored_permutation.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {6,5,4,6};
  vector<int> vec(a, a + sizeof(a) / sizeof(a[0]));
  int b[] = {2,4,1,5,3};
  vector<int> v = solution_.decode(vec);
  EXPECT_EQ(v.size(), sizeof(b) / sizeof(b[0]));
  for (size_t i = 0; i < v.size(); ++i) {
    EXPECT_EQ(v[i], b[i]);
  }
}

