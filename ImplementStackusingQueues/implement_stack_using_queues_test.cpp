/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 *
 * Source : https://leetcode.com/problems/implement-stack-using-queues/
 * Problem:	Implement Stack using Queues
 *
 */
#include <gtest/gtest.h>
#include "implement_stack_using_queues.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Stack st_;
};

TEST_F(SolutionTest, case1) {
	st_.push(1);
	st_.push(2);
	st_.push(3);
	EXPECT_EQ(st_.top(), 3);
	st_.pop();
	EXPECT_EQ(st_.top(), 2);
	st_.pop();
	EXPECT_EQ(st_.top(), 1);
	st_.pop();
	EXPECT_TRUE(st_.empty());
}

