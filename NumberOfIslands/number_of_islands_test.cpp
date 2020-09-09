/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/09
 *
 * Source : https://leetcode.com/problems/number-of-islands/
 * Problem:	Number of Islands
 *
 */
#include <gtest/gtest.h>
#include "number_of_islands.h"

TEST(SolutionTest, numIslands) {
  vector<vector<char> > vec2;
  vector<char> vec;

  vec.clear();
  vec.push_back('1');
  vec.push_back('1');
  vec.push_back('1');
  vec.push_back('1');
  vec.push_back('0');
  vec2.push_back(vec);

  vec.clear();
  vec.push_back('1');
  vec.push_back('1');
  vec.push_back('0');
  vec.push_back('1');
  vec.push_back('0');
  vec2.push_back(vec);

  vec.clear();
  vec.push_back('1');
  vec.push_back('1');
  vec.push_back('0');
  vec.push_back('0');
  vec.push_back('0');
  vec2.push_back(vec);

  vec.clear();
  vec.push_back('0');
  vec.push_back('0');
  vec.push_back('0');
  vec.push_back('0');
  vec.push_back('0');
  vec2.push_back(vec);

  Solution solution;
  EXPECT_EQ(solution.numIslands(vec2), 1);
}

