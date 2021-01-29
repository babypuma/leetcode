/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/29
 *
 * Source : https://leetcode-cn.com/problems/surrounded-regions/
 * Problem: Surrounded Regions
 *               
 */
#include <gtest/gtest.h>
#include "surrounder_regions.h"

class SolutionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
   virtual void TearDown() {
   }

   Solution solution_;
};

TEST_F(SolutionTest, case1) {
  vector<vector<char> > board;
  char row[] = {'X', 'X', 'X', 'X'};
  board.push_back(vector<char>(row, row + sizeof(row)/sizeof(row[0])));
  row[1] = 'O';
  row[2] = 'O';
  board.push_back(vector<char>(row, row + sizeof(row)/sizeof(row[0])));
  row[1] = 'X';
  board.push_back(vector<char>(row, row + sizeof(row)/sizeof(row[0])));
  row[1] = 'O';
  row[2] = 'X';
  board.push_back(vector<char>(row, row + sizeof(row)/sizeof(row[0])));
  solution_.solve(board);
  EXPECT_EQ(board[1][1], 'X');
  EXPECT_EQ(board[1][2], 'X');
  EXPECT_EQ(board[2][3], 'X');
  EXPECT_EQ(board[3][1], 'O');
}

