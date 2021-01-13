/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/13
 *
 * Source : https://leetcode-cn.com/problems/redundant-connection/
 * Problem: Redundant Connection
 *               
 */
#include <gtest/gtest.h>
#include "redundant_connection.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  struct Edge {
    int u;
    int v;
  };
  Edge edge[] = {
    {1,2}, {2,3}, {3,4}, {1,4}, {1,5}
  };
  vector<vector<int> > edges;
  for (size_t i = 0; i < sizeof(edge)/sizeof(edge[0]); ++i) {
    edges.push_back(vector<int>());
    edges.back().push_back(edge[i].u);
    edges.back().push_back(edge[i].v);
  }
  vector<int> red = solution_.findRedundantConnection(edges);
  ASSERT_EQ(red.size(), 2);
  EXPECT_EQ(red[0], 1);
  EXPECT_EQ(red[1], 4);
}

