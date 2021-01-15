/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/15
 *
 * Source : https://leetcode-cn.com/problems/single-number-ii/
 * Problem:	Single Number II
 *               
 */
#include <gtest/gtest.h>
#include "single_number_ii.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {0,1,0,1,0,1,99};
  vector<int> vec(a, a + sizeof(a)/sizeof(int));
  EXPECT_EQ(solution_.singleNumber(vec), 99);
}

