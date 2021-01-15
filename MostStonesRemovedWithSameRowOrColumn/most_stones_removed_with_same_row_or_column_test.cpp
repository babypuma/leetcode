/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/15
 *
 * Source : https://leetcode-cn.com/problems/most-stones-removed-with-same-row-or-column/
 * Problem: Most Stones Removed with Same Row or Column
 *               
 */
#include <gtest/gtest.h>
#include "most_stones_removed_with_same_row_or_column.h"

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
    {0,0},{0,1},{1,0},{1,2},{2,1},{2,2}
  };

  vector<vector<int> > stones;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    stones.push_back(vector<int>());
    stones.back().push_back(test_data[i].x);
    stones.back().push_back(test_data[i].y);
  }
  EXPECT_EQ(solution_.removeStones(stones), 5);
}

