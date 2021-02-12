/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/11
 *
 * Source : https://leetcode-cn.com/problems/jump-game-ii/
 * Problem: Jump Game II
 *               
 */
#include <gtest/gtest.h>
#include "jump_game_ii.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {2,3,1,1,4};
  vector<int> nums(a, a + sizeof(a) / sizeof(a[0]));
  EXPECT_EQ(solution_.jump(nums), 2);
}

TEST_F(SolutionTest, case2) {
  int a[] = {2,3,0,1,4};
  vector<int> nums(a, a + sizeof(a) / sizeof(a[0]));
  EXPECT_EQ(solution_.jump(nums), 2);
}

TEST_F(SolutionTest, case3) {
  int a[] = {0};
  vector<int> nums(a, a + sizeof(a) / sizeof(a[0]));
  EXPECT_EQ(solution_.jump(nums), 0);
}

