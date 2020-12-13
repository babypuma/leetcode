/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/13
 *
 * Source : https://leetcode-cn.com/problems/contains-duplicate/
 * Problem:	Contains Duplicate
 *               
 */
#include <gtest/gtest.h>
#include "contains_duplicate.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,2,3,1};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_TRUE(solution_.containsDuplicate(vec) == true);
}

