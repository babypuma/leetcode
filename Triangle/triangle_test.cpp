/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/19
 *
 * Source : https://leetcode-cn.com/problems/triangle/
 * Problem:	Triangle
 *
 */
#include <gtest/gtest.h>
#include "triangle.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, minimumTotal) {
  vector<vector<int> > vec2;
  vector<int> vec;
  vec.push_back(2);
  vec2.push_back(vec);

  vec.clear();
  vec.push_back(3);
  vec.push_back(4);
  vec2.push_back(vec);

  vec.clear();
  vec.push_back(6);
  vec.push_back(5);
  vec.push_back(7);
  vec2.push_back(vec);

  vec.clear();
  vec.push_back(4);
  vec.push_back(1);
  vec.push_back(8);
  vec.push_back(3);
  vec2.push_back(vec);
  EXPECT_EQ(solution_.minimumTotal(vec2), 11);
}

