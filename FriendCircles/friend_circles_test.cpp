/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/09
 *
 * Source : https://leetcode.com/problems/friend-circles/
 * Problem:	Friend Circles
 *
 */
#include <gtest/gtest.h>
#include "friend_circles.h"

TEST(SolutionTest, findCircleNum1) {
  vector<vector<int> > vec2;
  vector<int> vec;

  vec.clear();
  vec.push_back(1);
  vec.push_back(1);
  vec.push_back(0);
  vec2.push_back(vec);

  vec.clear();
  vec.push_back(1);
  vec.push_back(1);
  vec.push_back(0);
  vec2.push_back(vec);


  vec.clear();
  vec.push_back(0);
  vec.push_back(0);
  vec.push_back(1);
  vec2.push_back(vec);

  Solution solution;
  EXPECT_EQ(solution.findCircleNum(vec2), 2);
}

TEST(SolutionTest, findCircleNum2) {
  vector<vector<int> > vec2;
  vector<int> vec;

  vec.clear();
  vec.push_back(1);
  vec.push_back(1);
  vec.push_back(1);
  vec2.push_back(vec);

  vec.clear();
  vec.push_back(1);
  vec.push_back(1);
  vec.push_back(1);
  vec2.push_back(vec);


  vec.clear();
  vec.push_back(1);
  vec.push_back(1);
  vec.push_back(1);
  vec2.push_back(vec);

  Solution solution;
  EXPECT_EQ(solution.findCircleNum(vec2), 1);
}

