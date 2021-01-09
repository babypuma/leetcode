/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/09
 *
 * Source : https://leetcode-cn.com/problems/design-hit-counter/
 * Problem: Design Hit Counter
 *               
 */
#include <gtest/gtest.h>
#include "design_hit_counter.h"

TEST(SolutionTest, HitCounter) {
  HitCounter counter;
  counter.hit(1);
  counter.hit(2);
  counter.hit(3);
  EXPECT_EQ(counter.getHits(4), 3);
  counter.hit(300);
  EXPECT_EQ(counter.getHits(300), 4);
  EXPECT_EQ(counter.getHits(301), 3);
}

