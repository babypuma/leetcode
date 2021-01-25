/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/25
 *
 * Source : https://leetcode-cn.com/problems/regions-cut-by-slashes/
 * Problem: Regions Cut By Slashes
 *               
 */
#include <gtest/gtest.h>
#include "regions_cut_by_slashes.h"

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
    string s1;
    string s2;
    int n;
  };
  TestData test_data[] = {
    {" /", "/ ", 2},
    {" /", "  ", 1},
    {"\\/", "/\\", 4},
    {"/\\", "\\/", 5},
    {"//", "/ ", 3},
    {" /", "/ ", 2},
  };

  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    vector<string> grid;
    grid.push_back(test_data[i].s1);
    grid.push_back(test_data[i].s2);
    EXPECT_EQ(solution_.regionsBySlashes(grid), test_data[i].n);
  }
}

