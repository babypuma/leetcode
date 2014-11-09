/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/09
 *
 * Source : https://oj.leetcode.com/problems/add-binary/
 * Problem:	Add Binary
 *
 */
#include <gtest/gtest.h>
#include "add_binary.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	string str = solution_.addBinary(string("11"), string("1"));
	EXPECT_STREQ(str.c_str(), "100");
}

