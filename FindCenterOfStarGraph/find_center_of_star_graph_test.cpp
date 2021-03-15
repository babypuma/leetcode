/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/15
 *
 * Source : https://leetcode-cn.com/problems/find-center-of-star-graph/
 * Problem: Find Center of Star Graph
 *               
 */
#include <gtest/gtest.h>
#include "find_center_of_star_graph.h"

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
  Edge test_data[] = {
    {1,2},{2,3},{4,2}
  };

  vector<vector<int> > edges;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    edges.push_back(vector<int>());
    edges.back().push_back(test_data[i].u);
    edges.back().push_back(test_data[i].v);
  }
  EXPECT_EQ(solution_.findCenter(edges), 2);
}

