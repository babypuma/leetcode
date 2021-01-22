/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/23
 *
 * Source : https://leetcode-cn.com/problems/reverse-string/
 * Problem: Reverse String
 *               
 */
#include <gtest/gtest.h>
#include "reverse_string.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  char a[] = {'h', 'e', 'l', 'l', 'o'};
  vector<char> vec(a, a + sizeof(a)/sizeof(a[0]));
  char b[] = {'o', 'l', 'l', 'e', 'h'};
  solution_.reverseString(vec);
  for (size_t i = 0; i < vec.size(); ++i) {
    EXPECT_EQ(vec[i], b[i]);
  }
}

