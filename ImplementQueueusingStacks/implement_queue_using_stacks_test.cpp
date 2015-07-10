/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/07/10
 *
 * Source : https://leetcode.com/problems/implement-queue-using-stacks/
 * Problem:	Implement Queue using Stacks
 *
 */
#include <gtest/gtest.h>
#include "implement_queue_using_stacks.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Queue qu_;
};

TEST_F(SolutionTest, case1) {
	qu_.push(1);
	qu_.push(2);
	qu_.push(3);
	EXPECT_EQ(qu_.peek(), 1);
	qu_.pop();
	EXPECT_EQ(qu_.peek(), 2);
	qu_.pop();
	EXPECT_EQ(qu_.peek(), 3);
	qu_.pop();
	EXPECT_TRUE(qu_.empty());
}

