/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/15
 *
 * Source : https://leetcode-cn.com/problems/one-edit-distance/
 * Problem: One Edit Diatance
 *               
 */
#include <gtest/gtest.h>
#include "one_edit_distance.h"

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
    string s;
    string t;
    bool r;
  };
  TestData test_data[] = {
    {"ab", "acb", true},
    {"", "", false},
    {"a", "", true},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    EXPECT_TRUE(solution_.isOneEditDistance(test_data[i].s, test_data[i].t) == test_data[i].r);
  }
}

