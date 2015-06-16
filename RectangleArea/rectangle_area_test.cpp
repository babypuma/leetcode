/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 *
 * Source : https://leetcode.com/problems/rectangle-area/
 * Problem:	Rectangle Area
 *
 */
#include <gtest/gtest.h>
#include "rectangle_area.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	EXPECT_EQ(solution_.intersectionLength(7, 1, 9, 18), 2);
	EXPECT_EQ(solution_.intersectionLength(3, 1, 3, 18), 0);
}

TEST_F(SolutionTest, case2) {
	EXPECT_EQ(solution_.computeArea(-3, 0, 3, 4, 0, -1, 9, 2), 45);
	EXPECT_EQ(solution_.computeArea(-8, -4, 3, 2, 0, 1, 6, 7), 99);
	EXPECT_EQ(solution_.computeArea(3, 4, 8, 9, 4, 5, 6, 7), 25);
	EXPECT_EQ(solution_.computeArea(1, 2, 8, 9, 8, 10, 12, 13), 61);
}

