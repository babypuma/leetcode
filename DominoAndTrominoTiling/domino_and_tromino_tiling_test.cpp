/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/21
 *
 * Source : https://leetcode-cn.com/problems/domino-and-tromino-tiling/
 * Problem:	Domino and Tromino Tiling
 *
 */
#include <gtest/gtest.h>
#include "domino_and_tromino_tiling.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, numTilings) {
  EXPECT_EQ(solution_.numTilings(4), 11);
  EXPECT_EQ(solution_.numTilings(60), 882347204);
}

