/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/09
 *
 * Source : https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
 * Problem:	Evaluate Reverse Polish Notation
 *
 */
#include <gtest/gtest.h>
#include "evaluate_reverse_polish_notation.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	vector<string> tokens;
	tokens.push_back("2");
	tokens.push_back("1");
	tokens.push_back("+");
	tokens.push_back("3");
	tokens.push_back("*");
	EXPECT_EQ(solution_.evalRPN(tokens), 9);
}

TEST_F(SolutionTest, case2) {
	vector<string> tokens;
	tokens.push_back("4");
	tokens.push_back("13");
	tokens.push_back("5");
	tokens.push_back("/");
	tokens.push_back("+");
	EXPECT_EQ(solution_.evalRPN(tokens), 6);
}

TEST_F(SolutionTest, case3) {
	vector<string> tokens;
	tokens.push_back("-1");
	tokens.push_back("1");
	tokens.push_back("*");
	tokens.push_back("-1");
	tokens.push_back("+");
	EXPECT_EQ(solution_.evalRPN(tokens), -2);
}

