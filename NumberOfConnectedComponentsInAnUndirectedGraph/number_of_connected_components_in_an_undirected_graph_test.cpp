/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/04
 *
 * Source : https://leetcode-cn.com/problems/number-of-connected-components-in-an-undirected-graph/
 * Problem: Number of Connected Components in an Undirected Graph
 *               
 */
#include <gtest/gtest.h>
#include "number_of_connected_components_in_an_undirected_graph.h"

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
    int u;
    int v;
  };
  TestData test_data[] = {
    {0, 1}, {1, 2}, {3, 4},
  };

  vector<vector<int> > edges;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    edges.push_back(vector<int>());
    edges.back().push_back(test_data[i].u);
    edges.back().push_back(test_data[i].v);
  }
  EXPECT_EQ(solution_.countComponents(5, edges), 2);
}

