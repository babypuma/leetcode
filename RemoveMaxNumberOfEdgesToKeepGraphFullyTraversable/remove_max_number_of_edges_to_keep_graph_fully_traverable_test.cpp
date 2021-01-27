/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/27
 *
 * Source : https://leetcode-cn.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
 * Problem: Remove Max Number of Edges to Keep Graph Fully Traversable
 *               
 */
#include <gtest/gtest.h>
#include "remove_max_number_of_edges_to_keep_graph_fully_traverable.h"

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
    int type;
    int u;
    int v;
  };
  Edge test_data[] = {
    {3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4}
  };

  vector<vector<int> > edges;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    edges.push_back(vector<int>());
    edges.back().push_back(test_data[i].type);
    edges.back().push_back(test_data[i].u);
    edges.back().push_back(test_data[i].v);
  }
  EXPECT_EQ(solution_.maxNumEdgesToRemove(4, edges), 2);
}

TEST_F(SolutionTest, case2) {
  struct Edge {
    int type;
    int u;
    int v;
  };
  Edge test_data[] = {
    {3,2,3},{1,1,2},{2,3,4}
  };

  vector<vector<int> > edges;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    edges.push_back(vector<int>());
    edges.back().push_back(test_data[i].type);
    edges.back().push_back(test_data[i].u);
    edges.back().push_back(test_data[i].v);
  }
  EXPECT_EQ(solution_.maxNumEdgesToRemove(4, edges), -1);
}

