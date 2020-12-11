/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/12
 *
 * Source : https://leetcode-cn.com/problems/most-common-word/
 * Problem:	Most Common Word
 *               
 */
#include <gtest/gtest.h>
#include "most_common_word.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
  vector<string> banned;
  banned.push_back("hit");
  EXPECT_STREQ(solution_.mostCommonWord(paragraph, banned).c_str(), "ball");
}

