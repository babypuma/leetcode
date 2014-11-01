/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/01
 *
 * Source : https://oj.leetcode.com/problems/plus-one/
 * Problem:	Plus One
 *
 */
#include <gtest/gtest.h>
#include "plus_one.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	int a[] = {9, 9, 9};
	vector<int> vec(a, a + sizeof(a)/sizeof(int));
	vector<int> v = solution_.plusOne(vec);

	int b[] = {1, 0, 0, 0};
	ASSERT_EQ(sizeof(b)/sizeof(int), v.size());
	for (size_t i = 0; i < sizeof(b)/sizeof(int); i++) {
		EXPECT_EQ(b[i], v[i]);
	}
}

