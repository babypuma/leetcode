/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/19
 *
 * Source : https://leetcode-cn.com/problems/robot-return-to-origin/
 * Problem: Robot Return to Origin
 *               
 */
#include <gtest/gtest.h>
#include "robot_return_to_origin.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  struct TestData {
    string moves;
    bool reach;
  };
  TestData test_data[] = {
    {"UD", true},
    {"RRDD", false},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_TRUE(solution_.judgeCircle(test_data[i].moves) == test_data[i].reach);
  }
}

