/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/20
 *
 * Source : https://leetcode-cn.com/problems/minimum-swaps-to-make-sequences-increasing/
 * Problem:	Minimum Swaps To Make Sequences Increasing
 *
 */
#include <gtest/gtest.h>
#include "minimum_swaps_to_make_sequences_increasing.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, climbStairs) {
  vector<int> vec1;
  vec1.push_back(1);
  vec1.push_back(2);
  vec1.push_back(5);
  vec1.push_back(4);

  vector<int> vec2;
  vec2.push_back(1);
  vec2.push_back(2);
  vec2.push_back(3);
  vec2.push_back(7);
  EXPECT_EQ(solution_.minSwap(vec1, vec2), 1);
}

