/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 *
 * Source : https://leetcode.com/problems/happy-number/
 * Problem:	Happy Number
 * Description: 
 *
 */
#include <gtest/gtest.h>
#include "happy_number.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	EXPECT_TRUE(solution_.isHappy(19));
	EXPECT_TRUE(solution_.isHappy(100));
}

