#include <gtest/gtest.h>
#include "longest_common_prefix.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	vector<string> vec;
	vec.push_back("abc");
	vec.push_back("abcd");
	string str = solution_.longestCommonPrefix(vec);
	EXPECT_STREQ(str.c_str(), "abc");
}

TEST_F(SolutionTest, case2) {
	vector<string> vec;
	vec.push_back("");
	vec.push_back("abcd");
	string str = solution_.longestCommonPrefix(vec);
	EXPECT_STREQ(str.c_str(), "");
}

TEST_F(SolutionTest, case3) {
	vector<string> vec;
	vec.push_back("bcd");
	vec.push_back("abcd");
	string str = solution_.longestCommonPrefix(vec);
	EXPECT_STREQ(str.c_str(), "");
}

