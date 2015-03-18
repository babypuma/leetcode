/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/13
 *
 * Source : https://oj.leetcode.com/problems/multiply-strings/
 * Problem:	Multiply Strings
 *
 */
#include <gtest/gtest.h>
#include "multiply_strings.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	char mul;
	char flag; 

	flag = '0';
	mul = solution_.charMultiply('1', '2', flag);
	EXPECT_TRUE(mul == '2');
	EXPECT_TRUE(flag == '0');

	flag = '0';
	mul = solution_.charMultiply('2', '9', flag);
	EXPECT_TRUE(mul == '8');
	EXPECT_TRUE(flag == '1');

	flag = '0';
	mul = solution_.charMultiply('0', '9', flag);
	EXPECT_TRUE(mul == '0');
	EXPECT_TRUE(flag == '0');

	flag = '1';
	mul = solution_.charMultiply('1', '9', flag);
	EXPECT_TRUE(mul == '0');
	EXPECT_TRUE(flag == '1');
}

TEST_F(SolutionTest, case2) {
	string mul;

	mul = solution_.doMultiply('1', "123", 3);
	EXPECT_STREQ(mul.c_str(), "123");

	mul = solution_.doMultiply('4', "123", 3);
	EXPECT_STREQ(mul.c_str(), "4821");

	mul = solution_.doMultiply('4', "321", 3);
	EXPECT_STREQ(mul.c_str(), "294");

}

TEST_F(SolutionTest, case3) {
	string mul = solution_.multiply("123", "11");
	EXPECT_STREQ(mul.c_str(), "1353");
}

TEST_F(SolutionTest, case4) {
	string mul = solution_.multiply("0", "0");
	EXPECT_STREQ(mul.c_str(), "0");
}

TEST_F(SolutionTest, case5) {
	string mul = solution_.multiply("1", "1");
	EXPECT_STREQ(mul.c_str(), "1");
}

TEST_F(SolutionTest, case6) {
	string mul = solution_.multiply("123456789", "987654321");
	EXPECT_STREQ(mul.c_str(), "121932631112635269");
}

TEST_F(SolutionTest, case7) {
	string mul = solution_.multiply("167141802233061013023557397451289113296441069", "401716832807512840963");
	EXPECT_STREQ(mul.c_str(), "67143675422804947379429215144664313370120390398055713625298709447");
}

TEST_F(SolutionTest, case8) {
	string mul = solution_.multiply("9136", "0");
	EXPECT_STREQ(mul.c_str(), "0");
}

