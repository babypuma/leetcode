/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/14
 *
 * Source : https://leetcode-cn.com/problems/minimize-hamming-distance-after-swap-operations/
 * Problem: Minimize Hamming Distance After Swap Operations
 *               
 */
#include <gtest/gtest.h>
#include "minimize_hamming_distance_after_swap_operations.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

struct SwapPair {
  int i;
  int j;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,2,3,4};
  vector<int> source(a, a + sizeof(a)/sizeof(a[0]));
  int b[] = {2,1,4,5};
  vector<int> target(b, b + sizeof(b)/sizeof(b[0]));
  SwapPair s[] = {
    {0,1},
    {2,3},
  };
  vector<vector<int> > swap;
  for (size_t i = 0; i < sizeof(s)/sizeof(s[0]); ++i) {
    swap.push_back(vector<int>());
    swap.back().push_back(s[i].i);
    swap.back().push_back(s[i].j);
  }
  EXPECT_EQ(solution_.minimumHammingDistance(source, target, swap), 1);
}

TEST_F(SolutionTest, case2) {
  int a[] = {1,2,3,4};
  vector<int> source(a, a + sizeof(a)/sizeof(a[0]));
  int b[] = {1,3,2,4};
  vector<int> target(b, b + sizeof(b)/sizeof(b[0]));
  vector<vector<int> > swap;
  EXPECT_EQ(solution_.minimumHammingDistance(source, target, swap), 2);
}

TEST_F(SolutionTest, case3) {
  int a[] = {89,43,23,35,73,21,22,97,5,11,81,67,89,93,19,74};
  vector<int> source(a, a + sizeof(a)/sizeof(a[0]));
  int b[] = {68,43,21,46,41,21,26,5,14,71,4,30,52,2,47,74};
  vector<int> target(b, b + sizeof(b)/sizeof(b[0]));
  SwapPair s[] = {
    {12,2},{3,7},{9,15},{5,12},{6,11},{13,15},{4,1},{12,0},{9,3},{11,12},{4,11},{7,9},{7,2},{9,13},{15,12},{3,12},{12,8},{13,14},{11,2},{8,3},{14,10},{0,9},{12,9}
  };
  vector<vector<int> > swap;
  for (size_t i = 0; i < sizeof(s)/sizeof(s[0]); ++i) {
    swap.push_back(vector<int>());
    swap.back().push_back(s[i].i);
    swap.back().push_back(s[i].j);
  }
  EXPECT_EQ(solution_.minimumHammingDistance(source, target, swap), 12);
}

