/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/30
 *
 * Source : https://oj.leetcode.com/problems/valid-palindrome/
 * Problem:	Valid Palindrome 
 *
 */
#include <gtest/gtest.h>
#include "valid_palindrome.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	EXPECT_TRUE(solution_.isPalindrome("A man, a plan, a canal: Panama"));
}

TEST_F(SolutionTest, case2) {
	EXPECT_FALSE(solution_.isPalindrome("race a car"));
}

TEST_F(SolutionTest, case3) {
	EXPECT_TRUE(solution_.isPalindrome(",."));
}

