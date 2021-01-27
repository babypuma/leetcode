/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/28
 *
 * Source : https://leetcode-cn.com/problems/shortest-path-to-get-food/
 * Problem: Shortest Path to Get Food
 *               
 */
#include <gtest/gtest.h>
#include "shortest_path_to_get_food.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  char g[][6] = {
    {'X','X','X','X','X','X'},
    {'X','*','O','O','O','X'},
    {'X','O','O','#','O','X'},
    {'X','X','X','X','X','X'},
  };

  vector<vector<char> > grid;
  for (size_t i = 0; i < sizeof(g)/sizeof(char[6]); ++i) {
    grid.push_back(vector<char>());
    for (size_t j = 0; j < 6; ++j) {
      grid.back().push_back(g[i][j]);
    }
  }
  EXPECT_EQ(solution_.getFood(grid), 3);
}

TEST_F(SolutionTest, case2) {
  char g[][5] = {
    {'X','X','X','X','X'},{'X','*','X','O','X'},{'X','O','X','#','X'},{'X','X','X','X','X'}
  };

  vector<vector<char> > grid;
  for (size_t i = 0; i < sizeof(g)/sizeof(char[5]); ++i) {
    grid.push_back(vector<char>());
    for (size_t j = 0; j < 5; ++j) {
      grid.back().push_back(g[i][j]);
    }
  }
  EXPECT_EQ(solution_.getFood(grid), -1);
}

