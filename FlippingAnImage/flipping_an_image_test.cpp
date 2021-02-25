/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/24
 *
 * Source : https://leetcode-cn.com/problems/flipping-an-image/
 * Problem: Flipping an Image
 *               
 */
#include <gtest/gtest.h>
#include "flipping_an_image.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  vector<vector<int> > v;
  v.push_back(vector<int>());
  v.back().push_back(1);
  v.back().push_back(1);
  v.back().push_back(0);
  v.push_back(vector<int>());
  v.back().push_back(1);
  v.back().push_back(0);
  v.back().push_back(1);
  v.push_back(vector<int>());
  v.back().push_back(0);
  v.back().push_back(0);
  v.back().push_back(0);

  vector<vector<int> > v2 = solution_.flipAndInvertImage(v);
  EXPECT_EQ(v2.size(), 3);
  EXPECT_EQ(v2[0][0], 1);
  EXPECT_EQ(v2[0][1], 0);
  EXPECT_EQ(v2[0][2], 0);
  EXPECT_EQ(v2[1][0], 0);
  EXPECT_EQ(v2[1][1], 1);
  EXPECT_EQ(v2[1][2], 0);
  EXPECT_EQ(v2[2][0], 1);
  EXPECT_EQ(v2[2][1], 1);
  EXPECT_EQ(v2[2][2], 1);
}
