/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/01
 *
 * Source : https://leetcode.com/problems/word-search/
 * Problem:	Word Search
 *
 */
#include <gtest/gtest.h>
#include "word_search.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, exist) {
  Solution solution;
  vector<vector<char> > board;
  vector<char> vec;

  vec.push_back('A');
  vec.push_back('B');
  vec.push_back('C');
  vec.push_back('E');
  board.push_back(vec);

  vec.clear();
  vec.push_back('S');
  vec.push_back('F');
  vec.push_back('C');
  vec.push_back('S');
  board.push_back(vec);

  vec.clear();
  vec.push_back('A');
  vec.push_back('D');
  vec.push_back('E');
  vec.push_back('E');
  board.push_back(vec);

  struct TestCase {
    string word;
    bool res;
  };
  TestCase test_case[] = {
    {"ABCCED", true},
    {"SEE", true},
    {"ABCB", false},
    {"EEDA", true},
    {"ABE", false},
  };
  for (size_t i = 0; i < sizeof(test_case) / sizeof(test_case[0]); ++i) {
    EXPECT_TRUE(solution.exist(board, test_case[i].word) == test_case[i].res);
  }
}

