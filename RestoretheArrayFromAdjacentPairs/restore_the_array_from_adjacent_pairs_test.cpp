/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/31
 *
 * Source : https://leetcode-cn.com/problems/restore-the-array-from-adjacent-pairs/
 * Problem: Restore the Array From Adjacent Pairs
 *               
 */
#include <gtest/gtest.h>
#include "restore_the_array_from_adjacent_pairs.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  vector<vector<int> > adj;
  adj.push_back(vector<int>());
  adj.back().push_back(2);
  adj.back().push_back(1);
  adj.push_back(vector<int>());
  adj.back().push_back(3);
  adj.back().push_back(4);
  adj.push_back(vector<int>());
  adj.back().push_back(3);
  adj.back().push_back(2);
  int a[] = {4, 3, 2, 1};
  vector<int> v = solution_.restoreArray(adj);
  EXPECT_EQ(v.size(), sizeof(a)/sizeof(a[0]));
  for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
    EXPECT_EQ(v[i], a[i]);
  }
}

