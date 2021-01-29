/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/29
 *
 * Source : https://leetcode-cn.com/problems/strobogrammatic-number-ii/
 * Problem: Strobogrammatic Number II
 *               
 */
#include <gtest/gtest.h>
#include "strobogrammatic_number_ii.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  vector<string> v = solution_.findStrobogrammatic(2);
  EXPECT_EQ(v.size(), 4);
  EXPECT_STREQ(v[0].c_str(), "11");
  EXPECT_STREQ(v[1].c_str(), "69");
  EXPECT_STREQ(v[2].c_str(), "96");
  EXPECT_STREQ(v[3].c_str(), "88");
}

TEST_F(SolutionTest, case2) {
  vector<string> v = solution_.findStrobogrammatic(1);
  EXPECT_EQ(v.size(), 3);
  EXPECT_STREQ(v[0].c_str(), "0");
  EXPECT_STREQ(v[1].c_str(), "1");
  EXPECT_STREQ(v[2].c_str(), "8");
}

