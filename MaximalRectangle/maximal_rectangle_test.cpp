/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/26
 *
 * Source : https://leetcode-cn.com/problems/maximal-rectangle/
 * Problem:	Maximal Rectangle
 *
 */
#include <gtest/gtest.h>
#include "maximal_rectangle.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, maximalRectangle) {
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

  vec[1] = '1';
  vec2.push_back(vec);

  vec[1] = '0';
  vec[2] = '0';
  vec[4] = '0';
  vec2.push_back(vec);
  EXPECT_EQ(solution_.maximalRectangle(vec2), 6);
}

TEST_F(SolutionTest, maximalRectangle2) {
  vector<char> vec(1);
  vec[0] = '0';

  vector<vector<char> > vec2;
  vec2.push_back(vec);
  EXPECT_EQ(solution_.maximalRectangle(vec2), 0);
}

TEST_F(SolutionTest, maximalRectangle3) {
  vector<char> vec(1);
  vec[0] = '1';

  vector<vector<char> > vec2;
  vec2.push_back(vec);
  EXPECT_EQ(solution_.maximalRectangle(vec2), 1);
}

TEST_F(SolutionTest, maximalRectangle4) {
  vector<char> vec;
  vector<vector<char> > vec2;
  vec2.push_back(vec);
  EXPECT_EQ(solution_.maximalRectangle(vec2), 0);
}

TEST_F(SolutionTest, maximalRectangle5) {
  vector<char> vec(2);
  vec[0] = '0';
  vec[1] = '0';

  vector<vector<char> > vec2;
  vec2.push_back(vec);
  EXPECT_EQ(solution_.maximalRectangle(vec2), 0);
}

TEST_F(SolutionTest, maximalRectangle6) {
  vector<vector<char> > vec2;
  vector<char> vec(4);

  vec[0] = '1';
  vec[1] = '0';
  vec[2] = '1';
  vec[3] = '0';
  vec2.push_back(vec);

  vec[3] = '1';
  vec2.push_back(vec);

  vec2.push_back(vec);

  vec[1] = '1';
  vec2.push_back(vec);

  EXPECT_EQ(solution_.maximalRectangle(vec2), 6);
}

TEST_F(SolutionTest, maximalRectangle7) {
  vector<vector<char> > vec2;
  vector<char> vec(7);

  vec[0] = '0';
  vec[1] = '0';
  vec[2] = '0';
  vec[3] = '0';
  vec[4] = '0';
  vec[5] = '0';
  vec[6] = '1';
  vec2.push_back(vec);

  vec[4] = '1';
  vec[5] = '1';
  vec2.push_back(vec);

  vec[0] = '1';
  vec[1] = '1';
  vec[2] = '1';
  vec[3] = '1';
  vec2.push_back(vec);

  vec[0] = '0';
  vec[1] = '0';
  vec[2] = '0';
  vec2.push_back(vec);

  EXPECT_EQ(solution_.maximalRectangle(vec2), 9);
}

