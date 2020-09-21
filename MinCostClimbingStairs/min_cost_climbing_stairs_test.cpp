/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/21
 *
 * Source : https://leetcode-cn.com/problems/min-cost-climbing-stairs/
 * Problem:	Min Cost Climbing Stairs
 *
 */
#include <gtest/gtest.h>
#include "min_cost_climbing_stairs.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, numTilings) {
  vector<int> vec;
  vec.push_back(10);
  vec.push_back(15);
  vec.push_back(20);
  EXPECT_EQ(solution_.minCostClimbingStairs(vec), 15);
}

