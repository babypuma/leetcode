/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/11
 *
 * Source : https://leetcode-cn.com/problems/smallest-string-with-swaps/
 * Problem: Smallest String With Swaps
 *               
 */
#include <gtest/gtest.h>
#include "smallest_string_with_swaps.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, UF) {
  struct TestData {
    int i1;
    int i2;
  };
  TestData test_data[] = {
    {0,3},
    {1,2},
  };

  vector<vector<int> > pairs;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    pairs.push_back(vector<int>());
    pairs.back().push_back(test_data[i].i1);
    pairs.back().push_back(test_data[i].i2);
  }
  UF uf(4);
  for (auto& p : pairs) {
    uf.union_(p[0], p[1]);
  }
  EXPECT_EQ(uf.count(), 2);
  EXPECT_EQ(uf.find(0), 0);
  EXPECT_EQ(uf.find(3), 0);
  EXPECT_EQ(uf.findUnionSize(0), 2);
  EXPECT_EQ(uf.findUnionSize(3), 2);
  EXPECT_EQ(uf.find(1), 1);
  EXPECT_EQ(uf.find(2), 1);
  EXPECT_EQ(uf.findUnionSize(1), 2);
  EXPECT_EQ(uf.findUnionSize(2), 2);
}

TEST_F(SolutionTest, LetterCommunity) {
  LetterCommunity lc;
  EXPECT_TRUE(lc.empty());
  lc.add('a');
  EXPECT_FALSE(lc.empty());
  lc.add('c');
  EXPECT_FALSE(lc.empty());
  EXPECT_EQ(lc.getMin(), 'a');
  EXPECT_FALSE(lc.empty());
  EXPECT_EQ(lc.getMin(), 'c');
  EXPECT_TRUE(lc.empty());
}

TEST_F(SolutionTest, smallestStringWithSwaps) {
  struct TestData {
    int i1;
    int i2;
  };
  TestData test_data[] = {
    {0,3},
    {1,2},
  };

  vector<vector<int> > pairs;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    pairs.push_back(vector<int>());
    pairs.back().push_back(test_data[i].i1);
    pairs.back().push_back(test_data[i].i2);
  }
  EXPECT_STREQ(solution_.smallestStringWithSwaps("dcab", pairs).c_str(), "bacd");
}
