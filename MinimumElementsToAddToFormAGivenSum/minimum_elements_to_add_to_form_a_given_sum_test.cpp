/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/09
 *
 * Source : https://leetcode-cn.com/problems/minimum-elements-to-add-to-form-a-given-sum/
 * Problem: Minimum Elements to Add to Form a Given Sum
 *               
 */
#include <gtest/gtest.h>
#include "minimum_elements_to_add_to_form_a_given_sum.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,-1,1};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.minElements(vec, 3, -4), 2);
}

