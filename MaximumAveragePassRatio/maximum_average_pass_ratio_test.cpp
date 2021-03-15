/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/15
 *
 * Source : https://leetcode-cn.com/problems/maximum-average-pass-ratio/
 * Problem: Maximum Average Pass Ratio
 *               
 */
#include <gtest/gtest.h>
#include "maximum_average_pass_ratio.h"

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
    int pass;
    int total;
  };
  TestData test_data[] = {
    {1,2},{3,5},{2,2}
  };

  vector<vector<int> > classes;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    classes.push_back(vector<int>());
    classes.back().push_back(test_data[i].pass);
    classes.back().push_back(test_data[i].total);
  }
  EXPECT_DOUBLE_EQ(solution_.maxAverageRatio(classes, 2), 0.78333333333333333);
}

