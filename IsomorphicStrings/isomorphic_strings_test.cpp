/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 * Update : 2021/01/20
 *
 * Source : https://leetcode-cn.com/problems/isomorphic-strings/
 * Problem:	Isomorphic Strings
 *
 */
#include <gtest/gtest.h>
#include "isomorphic_strings.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  EXPECT_TRUE(solution_.isIsomorphic("egg", "add"));
  EXPECT_TRUE(solution_.isIsomorphic("paple", "title"));
  EXPECT_FALSE(solution_.isIsomorphic("foo", "bar"));
}

TEST_F(SolutionTest, case2) {
  EXPECT_FALSE(solution_.isIsomorphic("ab", "aa"));
}

