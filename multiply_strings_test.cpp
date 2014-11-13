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

TEST_F(SolutionTest, case6) {
	string mul = solution_.multiply("1", "1");
	EXPECT_STREQ(mul.c_str(), "1");
}

