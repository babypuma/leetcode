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
#include "verifying_an_alien_dictionary.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  string a[] = {"hello","leetcode"};
  vector<string> vec(a, a + sizeof(a)/sizeof(a[0]));
  string order = "hlabcdefgijkmnopqrstuvwxyz";
  EXPECT_TRUE(solution_.isAlienSorted(vec, order));
}

TEST_F(SolutionTest, case2) {
  string a[] = {"word","world","row"};
  vector<string> vec(a, a + sizeof(a)/sizeof(a[0]));
  string order = "worldabcefghijkmnpqstuvxyz";
  EXPECT_FALSE(solution_.isAlienSorted(vec, order));
}

TEST_F(SolutionTest, case3) {
  string a[] = {"apple","app"};
  vector<string> vec(a, a + sizeof(a)/sizeof(a[0]));
  string order = "abcdefghijklmnopqrstuvwxyz";
  EXPECT_FALSE(solution_.isAlienSorted(vec, order));
}

