/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/15
 *
 * Source : https://leetcode-cn.com/problems/single-number-iii/
 * Problem:	Single Number III
 *               
 */
#include <gtest/gtest.h>
#include "single_number_iii.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,2,1,3,2,5};
  vector<int> vec(a, a + sizeof(a)/sizeof(int));
  vector<int> single_vec = solution_.singleNumber(vec);
  int b[] = {3,5};
  EXPECT_EQ(single_vec.size(), sizeof(b)/sizeof(b[0]));
  EXPECT_EQ(single_vec[0], b[0]);
  EXPECT_EQ(single_vec[1], b[1]);
}

