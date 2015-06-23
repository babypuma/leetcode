 /*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/17
 *
 * Source : https://leetcode.com/problems/basic-calculator/
 * Problem:	Basic Calculator
 *
 */
#include <gtest/gtest.h>
#include "basic_calculator.h"

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
	str = "(4+5-2)";
	EXPECT_EQ(solution_.calculate(str), 7);
}

TEST_F(SolutionTest, case4) {
	string str;
	str = "(4+5-2)-3";
	EXPECT_EQ(solution_.calculate(str), 4);
}

TEST_F(SolutionTest, case5) {
	string str;
	str = "(1+(4+5-2)-3)+(6+8)";
	EXPECT_EQ(solution_.calculate(str), 19);
}

TEST_F(SolutionTest, case6) {
	string str;
	str = "(1-(3-4))";
	EXPECT_EQ(solution_.calculate(str), 2);
}

TEST_F(SolutionTest, case7) {
	string str;
	str = "1-(3+5-2+(3+19-(3-1-4+(9-4-(4-(1+(3)-2)-5)+8-(3-5)-1)-4)-5)-4+3-9)-4-(3+2-5)-10";
	EXPECT_EQ(solution_.calculate(str), -15);
}

TEST_F(SolutionTest, case8) {
	string str;
	str = "(7)-(0)+(4)";
	EXPECT_EQ(solution_.calculate(str), 11);
}

TEST_F(SolutionTest, case9) {
	string str;
	str = "2-4-(8+2-6+(8+4-(1)+8-10))";
	//str = "2-4-(8+2-6+(8+4-1+8-10))";
	EXPECT_EQ(solution_.calculate(str), -15);
}

