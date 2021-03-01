/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/26
 *
 * Source : https://leetcode-cn.com/problems/number-of-valid-words-for-each-puzzle/
 * Problem: Number of Valid Words for Each Puzzle
 *               
 */
#include <gtest/gtest.h>
#include "number_of_valid_words_for_each_puzzle.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  string a[] = {"aaaa","asas","able","ability","actt","actor","access"};
  vector<string> words(a, a + sizeof(a)/sizeof(a[0]));
  string b[] = {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
  vector<string> puzzles(b, b + sizeof(b)/sizeof(b[0]));
  int c[] = {1,1,3,2,4,0};
  vector<int> v = solution_.findNumOfValidWords(words, puzzles);
  EXPECT_EQ(v.size(), sizeof(c)/sizeof(c[0]));
  for (size_t i = 0; i < v.size(); ++i) {
    EXPECT_EQ(v[i], c[i]);
  }
}

