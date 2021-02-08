/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/07
 *
 * Source : https://leetcode-cn.com/problems/maximum-score-from-removing-stones/
 * Problem: Maximum Score From Removing Stones
 *               
 */
#include <gtest/gtest.h>
#include "maximum_score_from_removing_stones.h"

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
    int a;
    int b;
    int c;
    int s;
  };
  TestData test_data[] = {
    {2,4,6,6},
    {4,4,6,7},
    {1,8,8,8},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_EQ(solution_.maximumScore(test_data[i].a, test_data[i].b, test_data[i].c), test_data[i].s);
  }
}

