/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/18
 *
 * Source : https://leetcode-cn.com/problems/minimum-path-sum/
 * Problem:	Minimum Path Sum
 *
 */
#include <gtest/gtest.h>
#include "minimum_path_sum.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, minPathSum) {
  vector<vector<int> > vec2;
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(3);
  vec.push_back(1);
  vec2.push_back(vec);

  vec.clear();
  vec.push_back(1);
  vec.push_back(5);
  vec.push_back(1);
  vec2.push_back(vec);

  vec.clear();
  vec.push_back(4);
  vec.push_back(2);
  vec.push_back(1);
  vec2.push_back(vec);
  EXPECT_EQ(solution_.minPathSum(vec2), 7);
}

