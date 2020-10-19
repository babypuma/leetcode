/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/19
 *
 * Source : https://leetcode-cn.com/problems/maximal-square/
 * Problem:	Maximal Square
 *
 */
#include <gtest/gtest.h>
#include "maximal_square.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, maximalSquare) {
  vector<vector<char> > vec2;
  vector<char> vec(5);
  vec[0] = '1';
  vec[1] = '0';
  vec[2] = '1';
  vec[3] = '0';
  vec[4] = '0';
  vec2.push_back(vec);

  vec[3] = '1';
  vec[4] = '1';
  vec2.push_back(vec);

  vec[2] = '1';
  vec2.push_back(vec);

  vec[1] = '0';
  vec[2] = '0';
  vec[4] = '0';
  vec2.push_back(vec);
  vec2.push_back(vec);
  vec2.push_back(vec);
  EXPECT_EQ(solution_.maximalSquare(vec2), 4);
}

TEST_F(SolutionTest, maximalSquare2) {
  vector<char> vec(2);
  vec[0] = '0';
  vec[1] = '1';

  vector<vector<char> > vec2;
  vec2.push_back(vec);
  EXPECT_EQ(solution_.maximalSquare(vec2), 1);
}

