 /*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/24
 *
 * Source : https://leetcode.com/problems/basic-calculator-ii/
 * Problem:	Basic Calculator II
 *
 */
#include <gtest/gtest.h>
#include "basic_calculator_ii.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	string str;
	str = "1 + 1";
	EXPECT_EQ(solution_.calculate(str), 2);
}

TEST_F(SolutionTest, case2) {
	string str;
	str = " 2-1 + 2";
	EXPECT_EQ(solution_.calculate(str), 3);
}

TEST_F(SolutionTest, case3) {
	string str;
	str = "3+2*2";
	EXPECT_EQ(solution_.calculate(str), 7);
}

TEST_F(SolutionTest, case4) {
	string str;
	str = " 3/2 ";
	EXPECT_EQ(solution_.calculate(str), 1);
}

TEST_F(SolutionTest, case5) {
	string str;
	str = " 3+5 / 2 ";
	EXPECT_EQ(solution_.calculate(str), 5);
}

