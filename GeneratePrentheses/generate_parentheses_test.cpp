#include <gtest/gtest.h>
#include "generate_parentheses.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	vector<string> vec = solution_.generateParenthesis(3);
	EXPECT_EQ((int)vec.size(), 5);
	char *str[] = {"((()))", "(()())", "(())()", "()(())", "()()()"};
	for (size_t i = 0; i < sizeof(str)/sizeof(char *); i++) {
		EXPECT_TRUE(find(vec.begin(), vec.end(), string(str[i])) != vec.end());
	}
}

TEST_F(SolutionTest, case2) {
	vector<string> vec = solution_.generateParenthesis(1);
	EXPECT_EQ((int)vec.size(), 1);
	EXPECT_STREQ(vec[0].c_str(), "()");
}

