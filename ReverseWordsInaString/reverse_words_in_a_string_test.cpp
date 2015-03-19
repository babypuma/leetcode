/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/03
 *
 * Source : https://oj.leetcode.com/problems/reverse-words-in-a-string/
 * Problem:	Reverse Words in a String
 *
 */
#include <gtest/gtest.h>
#include "reverse_words_in_a_string.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	string str("the sky is blue");
	solution_.reverseWords(str);
	EXPECT_STREQ(str.c_str(), "blue is sky the");
}

TEST_F(SolutionTest, case2) {
	string str(" ");
	solution_.reverseWords(str);
	EXPECT_STREQ(str.c_str(), "");
}

TEST_F(SolutionTest, case3) {
	string str("");
	solution_.reverseWords(str);
	EXPECT_STREQ(str.c_str(), "");
}

TEST_F(SolutionTest, case4) {
	string str(" 1");
	solution_.reverseWords(str);
	EXPECT_STREQ(str.c_str(), "1");
}

TEST_F(SolutionTest, case5) {
	string str("  a  b");
	solution_.reverseWords(str);
	EXPECT_STREQ(str.c_str(), "b a");
}

TEST_F(SolutionTest, case6) {
	string str("a");
	solution_.reverseWords(str);
	EXPECT_STREQ(str.c_str(), "a");
}

