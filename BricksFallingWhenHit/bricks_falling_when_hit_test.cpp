/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/06
 *
 * Source : https://leetcode-cn.com/problems/bricks-falling-when-hit/
 * Problem: Bricks Falling When Hit
 *               
 */
#include <gtest/gtest.h>
#include "bricks_falling_when_hit.h"

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
    int x1;
    int x2;
    int x3;
    int x4;
  };
  TestData test_data[] = {
    {1,0,0,0},
    {1,1,1,0},
  };
  vector<vector<int> > grid;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    grid.push_back(vector<int>());
    grid.back().push_back(test_data[i].x1);
    grid.back().push_back(test_data[i].x2);
    grid.back().push_back(test_data[i].x3);
    grid.back().push_back(test_data[i].x4);
  }
  vector<vector<int> > hits;
  hits.push_back(vector<int>());
  hits.back().push_back(1);
  hits.back().push_back(0);
  vector<int> c = solution_.hitBricks(grid, hits);
  EXPECT_EQ(c.size(), 1);
  EXPECT_EQ(c[0], 2);
}

TEST_F(SolutionTest, case2) {
  struct TestData {
    int x1;
    int x2;
    int x3;
    int x4;
  };
  TestData test_data[] = {
    {1,0,0,0},
    {1,1,0,0},
  };
  vector<vector<int> > grid;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    grid.push_back(vector<int>());
    grid.back().push_back(test_data[i].x1);
    grid.back().push_back(test_data[i].x2);
    grid.back().push_back(test_data[i].x3);
    grid.back().push_back(test_data[i].x4);
  }
  vector<vector<int> > hits;
  hits.push_back(vector<int>());
  hits.back().push_back(1);
  hits.back().push_back(1);
  hits.push_back(vector<int>());
  hits.back().push_back(1);
  hits.back().push_back(0);
  vector<int> c = solution_.hitBricks(grid, hits);
  ASSERT_EQ(c.size(), 2);
  EXPECT_EQ(c[0], 0);
  EXPECT_EQ(c[1], 0);
}

TEST_F(SolutionTest, case3) {
  struct TestData {
    int x1;
  };
  TestData test_data[] = {
    {1},
    {1},
    {1},
    {1},
    {1},
  };
  vector<vector<int> > grid;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    grid.push_back(vector<int>());
    grid.back().push_back(test_data[i].x1);
  }
  vector<vector<int> > hits;
  hits.push_back(vector<int>());
  hits.back().push_back(3);
  hits.back().push_back(0);
  hits.push_back(vector<int>());
  hits.back().push_back(4);
  hits.back().push_back(0);
  hits.push_back(vector<int>());
  hits.back().push_back(1);
  hits.back().push_back(0);
  hits.push_back(vector<int>());
  hits.back().push_back(2);
  hits.back().push_back(0);
  hits.push_back(vector<int>());
  hits.back().push_back(0);
  hits.back().push_back(0);
  vector<int> c = solution_.hitBricks(grid, hits);
  ASSERT_EQ(c.size(), 5);
  EXPECT_EQ(c[0], 1);
  EXPECT_EQ(c[1], 0);
  EXPECT_EQ(c[2], 1);
  EXPECT_EQ(c[3], 0);
  EXPECT_EQ(c[4], 0);
}

