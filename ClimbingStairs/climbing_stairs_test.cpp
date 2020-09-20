/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/20
 *
 * Source : https://leetcode-cn.com/problems/climbing-stairs/
 * Problem:	Climbing Stairs
 *
 */
#include <gtest/gtest.h>
#include "climbing_stairs.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, climbStairs) {
  EXPECT_EQ(solution_.climbStairs(3), 3);
}

