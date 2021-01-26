/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/26
 *
 * Source : https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs/
 * Problem: Number of Equivalent Domino Pairs
 *               
 */
#include <gtest/gtest.h>
#include "number_of_equivalent_domino_pairs.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  vector<vector<int> > dominoes;
  dominoes.push_back(vector<int>());
  dominoes.back().push_back(1);
  dominoes.back().push_back(2);
  dominoes.push_back(vector<int>());
  dominoes.back().push_back(2);
  dominoes.back().push_back(1);
  dominoes.push_back(vector<int>());
  dominoes.back().push_back(3);
  dominoes.back().push_back(4);
  dominoes.push_back(vector<int>());
  dominoes.back().push_back(5);
  dominoes.back().push_back(6);

  EXPECT_EQ(solution_.numEquivDominoPairs(dominoes), 1);
}

