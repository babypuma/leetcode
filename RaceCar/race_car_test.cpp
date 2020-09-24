/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/24
 *
 * Source : https://leetcode-cn.com/problems/race-car/
 * Problem: Race Car
 *
 */
#include <gtest/gtest.h>
#include "race_car.h"

TEST(SolutionTest, racecar) {
  Solution solution_;
  EXPECT_EQ(solution_.racecar(1), 1);
}

TEST(SolutionTest, racecar1) {
  Solution solution_;
  EXPECT_EQ(solution_.racecar(2), 4);
}

TEST(SolutionTest, racecar2) {
  Solution solution_;
  EXPECT_EQ(solution_.racecar(3), 2);
}

TEST(SolutionTest, racecar3) {
  Solution solution_;
  EXPECT_EQ(solution_.racecar(4), 5);
}

TEST(SolutionTest, racecar4) {
  Solution solution_;
  EXPECT_EQ(solution_.racecar(5), 7);
}

TEST(SolutionTest, racecar5) {
  Solution solution_;
  EXPECT_EQ(solution_.racecar(6), 5);
}

TEST(SolutionTest, racecar6) {
  Solution solution_;
  EXPECT_EQ(solution_.racecar(7), 3);
}

TEST(SolutionTest, racecar7) {
  Solution solution_;
  EXPECT_EQ(solution_.racecar(8), 6);
}

TEST(SolutionTest, racecar8) {
  Solution solution_;
  EXPECT_EQ(solution_.racecar(9), 8);
}

TEST(SolutionTest, racecar9) {
  Solution solution_;
  EXPECT_EQ(solution_.racecar(10), 7);
}

TEST(SolutionTest, racecar10) {
  Solution solution_;
  EXPECT_EQ(solution_.racecar(11), 10);
}

TEST(SolutionTest, racecar11) {
  Solution solution_;
  EXPECT_EQ(solution_.racecar(12), 7);
}

TEST(SolutionTest, racecar12) {
  Solution solution_;
  EXPECT_EQ(solution_.racecar(13), 9);
}

TEST(SolutionTest, racecar13) {
  Solution solution_;
  EXPECT_EQ(solution_.racecar(14), 6);
}

TEST(SolutionTest, racecar14) {
  Solution solution_;
  EXPECT_EQ(solution_.racecar(15), 4);
}
