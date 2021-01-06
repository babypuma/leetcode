/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/14
 *
 * Source : https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 * Problem: Median of Two Sorted Arrays
 *               
 */
#include <gtest/gtest.h>
#include "coin_change.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  int a[] = {1,2,5};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.coinChange(vec, 11), 3);
}

TEST_F(SolutionTest, case2) {
  int a[] = {2};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.coinChange(vec, 3), -1);
}

TEST_F(SolutionTest, case3) {
  int a[] = {1};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.coinChange(vec, 0), 0);
}

TEST_F(SolutionTest, case4) {
  int a[] = {186,419,83,408};
  vector<int> vec(a, a + sizeof(a)/sizeof(a[0]));
  EXPECT_EQ(solution_.coinChange(vec, 6249), 20);
}

