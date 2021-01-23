/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/23
 *
 * Source : https://leetcode-cn.com/problems/number-of-operations-to-make-network-connected/
 * Problem: Number of Operations to Make Network Connected
 *               
 */
#include <gtest/gtest.h>
#include "number_of_operations_to_make_network_connected.h"

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
    {0,1},{0,2},{0,3},{1,2},{1,3}
  };

  vector<vector<int> > connections;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    connections.push_back(vector<int>());
    connections.back().push_back(test_data[i].u);
    connections.back().push_back(test_data[i].v);
  }
  EXPECT_EQ(solution_.makeConnected(6, connections), 2);
}

