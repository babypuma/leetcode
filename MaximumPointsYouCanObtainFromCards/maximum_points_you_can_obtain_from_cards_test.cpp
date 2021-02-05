/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/06
 *
 * Source : https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards/
 * Problem: Maximum Points You Can Obtain from Cards
 *               
 */
#include <gtest/gtest.h>
#include "maximum_points_you_can_obtain_from_cards.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,79,80,1,1,1,200,1};
  vector<int> points(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.maxScore(points, 3), 202);
}

