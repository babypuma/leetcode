/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/12
 * Update : 2020/12/16
 *
 * Source : https://leetcode-cn.com/problems/length-of-last-word/
 * Problem:	Length of Last Word
 *
 */
#include <gtest/gtest.h>
#include "length_of_last_word.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  EXPECT_EQ(solution_.lengthOfLastWord("Hello world"), 5);
}

TEST_F(SolutionTest, case2) {
  EXPECT_EQ(solution_.lengthOfLastWord("Hello world "), 5);
}

TEST_F(SolutionTest, case3) {
  EXPECT_EQ(solution_.lengthOfLastWord(""), 0);
}

TEST_F(SolutionTest, case4) {
  EXPECT_EQ(solution_.lengthOfLastWord("a "), 1);
}

