/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/07
 *
 * Source : https://oj.leetcode.com/problems/gray-code/
 * Problem:	Gray Code
 *
 */
#include <gtest/gtest.h>
#include "gray_code.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	vector<int> vec = solution_.grayCode(2);

	int a[] = {0, 1, 3, 2};
	ASSERT_EQ(sizeof(a)/sizeof(int), vec.size());
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++) {
		EXPECT_EQ(a[i], vec[i]);
	}
}

