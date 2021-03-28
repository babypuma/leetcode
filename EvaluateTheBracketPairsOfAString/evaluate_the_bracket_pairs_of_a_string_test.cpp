/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/28
 *
 * Source : https://leetcode-cn.com/problems/evaluate-the-bracket-pairs-of-a-string/
 * Problem: Evaluate the Bracket Pairs of a String
 *               
 */
#include <gtest/gtest.h>
#include "evaluate_the_bracket_pairs_of_a_string.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  vector<vector<string> > knowledge;
  knowledge.push_back(vector<string>());
  knowledge.back().push_back("name");
  knowledge.back().push_back("bob");
  knowledge.push_back(vector<string>());
  knowledge.back().push_back("age");
  knowledge.back().push_back("two");
  EXPECT_STREQ(solution_.evaluate("(name)is(age)yearsold", knowledge).c_str(), "bobistwoyearsold");
}

