/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/02
 *
 * Source : https://leetcode-cn.com/problems/k-closest-points-to-origin/
 * Problem: K Closest Points to Origin
 *               
 */
#include <gtest/gtest.h>
#include "k_closest_points_to_origin.h"

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
    {1,3},
    {-2,2},
  };

  vector<vector<int> > points;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    points.push_back(vector<int>());
    points.back().push_back(test_data[i].x);
    points.back().push_back(test_data[i].y);
  }
  vector<vector<int> > p = solution_.kClosest(points, 1);
  EXPECT_EQ(p.size(), 1);
  EXPECT_EQ(p[0][0], -2);
  EXPECT_EQ(p[0][1], 2);
}

