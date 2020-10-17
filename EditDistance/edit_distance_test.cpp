/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/17
 *
 * Source : https://leetcode-cn.com/problems/edit-distance/
 * Problem:	Edit Distance
 *
 */
#include <gtest/gtest.h>
#include "edit_distance.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, minDistance) {
  struct TestData {
    string str1;
    string str2;
    int dist;
  };
  TestData test_data[] = {
    {"horse", "ros", 3},
    {"intention", "execution", 5},
    {"plasma", "altruism", 6},
  };
  for (size_t i = 0; i < sizeof(test_data) / sizeof(test_data[0]); ++i) {
    int dist = solution_.minDistance(test_data[i].str1, test_data[i].str2);
    EXPECT_EQ(dist, test_data[i].dist);
  } 
}

