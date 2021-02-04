/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/04
 *
 * Source : https://leetcode-cn.com/problems/count-unhappy-friends/
 * Problem: Count Unhappy Friends
 *               
 */
#include <gtest/gtest.h>
#include "count_unhappy_friends.h"

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
    int p1;
    int p2;
    int p3;
    int p4;
    int p5;
  };
  TestData test_data[] = {
    {1,4,3,2,5},{0,5,4,3,2},{3,0,1,5,4},{2,1,4,0,5},{2,1,0,3,5},{3,4,2,0,1}
  };

  vector<vector<int> > preferences;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    preferences.push_back(vector<int>());
    preferences.back().push_back(test_data[i].p1);
    preferences.back().push_back(test_data[i].p2);
    preferences.back().push_back(test_data[i].p3);
    preferences.back().push_back(test_data[i].p4);
    preferences.back().push_back(test_data[i].p5);
  }

  vector<vector<int> > pairs;
  pairs.push_back(vector<int>());
  pairs.back().push_back(1);
  pairs.back().push_back(3);
  pairs.push_back(vector<int>());
  pairs.back().push_back(2);
  pairs.back().push_back(0);
  pairs.push_back(vector<int>());
  pairs.back().push_back(5);
  pairs.back().push_back(4);

  EXPECT_EQ(solution_.unhappyFriends(6, preferences, pairs), 5);
}

TEST_F(SolutionTest, case2) {
  struct TestData {
    int p1;
    int p2;
    int p3;
  };
  TestData test_data[] = {
    {1, 2, 3}, {3, 2, 0}, {3, 1, 0}, {1, 2, 0}
  };

  vector<vector<int> > preferences;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    preferences.push_back(vector<int>());
    preferences.back().push_back(test_data[i].p1);
    preferences.back().push_back(test_data[i].p2);
    preferences.back().push_back(test_data[i].p3);
  }
  vector<vector<int> > pairs;
  pairs.push_back(vector<int>());
  pairs.back().push_back(0);
  pairs.back().push_back(1);
  pairs.push_back(vector<int>());
  pairs.back().push_back(2);
  pairs.back().push_back(3);

  EXPECT_EQ(solution_.unhappyFriends(4, preferences, pairs), 2);
}

