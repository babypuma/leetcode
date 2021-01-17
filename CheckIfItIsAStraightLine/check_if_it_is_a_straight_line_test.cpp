/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/07
 *
 * Source : https://leetcode-cn.com/problems/check-if-it-is-a-straight-line/
 * Problem: Check If It Is a Straight Line
 *               
 */
#include <gtest/gtest.h>
#include "check_if_it_is_a_straight_line.h"

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
    int x;
    int y;
  };
  TestData test_data[] = {
    {1,2},{2,3},{3,4},{4,5},{5,6},{6,7},
  };

  vector<vector<int> > vec;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    vec.push_back(vector<int>());
    vec.back().push_back(test_data[i].x);
    vec.back().push_back(test_data[i].y);
  }
  EXPECT_TRUE(solution_.checkStraightLine(vec));
}

TEST_F(SolutionTest, case2) {
  struct TestData {
    int x;
    int y;
  };
  TestData test_data[] = {
    {2,1},{4,2},{6,3},
  };

  vector<vector<int> > vec;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    vec.push_back(vector<int>());
    vec.back().push_back(test_data[i].x);
    vec.back().push_back(test_data[i].y);
  }
  EXPECT_TRUE(solution_.checkStraightLine(vec));
}

TEST_F(SolutionTest, case3) {
  struct TestData {
    int x;
    int y;
  };
  TestData test_data[] = {
    {0, 0}, {0, 1}, {0, -1},
  };

  vector<vector<int> > vec;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    vec.push_back(vector<int>());
    vec.back().push_back(test_data[i].x);
    vec.back().push_back(test_data[i].y);
  }
  EXPECT_TRUE(solution_.checkStraightLine(vec));
}

TEST_F(SolutionTest, case4) {
  struct TestData {
    int x;
    int y;
  };
  TestData test_data[] = {
    {1, 0}, {0, 0}, {-1, 0},
  };

  vector<vector<int> > vec;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    vec.push_back(vector<int>());
    vec.back().push_back(test_data[i].x);
    vec.back().push_back(test_data[i].y);
  }
  EXPECT_TRUE(solution_.checkStraightLine(vec));
}

