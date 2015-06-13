/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/12
 *
 * Source : https://oj.leetcode.com/problems/min-stack/
 * Problem:	Min Stack
 *
 */
#include <gtest/gtest.h>
#include "min_stack.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        MinStack solution_;
};

TEST_F(SolutionTest, case1) {
	MinStack mstack;
	for (int i = 100; i >= 0; i--) {
		mstack.push(i);
		EXPECT_EQ(mstack.getMin(), i);
		EXPECT_EQ(mstack.top(), i);
	}
	EXPECT_EQ(mstack.getMin(), 0);
	EXPECT_EQ(mstack.top(), 0);
	mstack.pop();
	EXPECT_EQ(mstack.getMin(), 1);
	EXPECT_EQ(mstack.top(), 1);
}

TEST_F(SolutionTest, case2) {
	MinStack mstack;
	for (int i = 0; i < 100; i++) {
		mstack.push(i);
		EXPECT_EQ(mstack.getMin(), 0);
		EXPECT_EQ(mstack.top(), i);
	}
	EXPECT_EQ(mstack.getMin(), 0);
	EXPECT_EQ(mstack.top(), 99);
	mstack.pop();
	EXPECT_EQ(mstack.getMin(), 0);
	EXPECT_EQ(mstack.top(), 98);
}

