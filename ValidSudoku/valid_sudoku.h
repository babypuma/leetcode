/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/12
 *
 * Source : https://leetcode-cn.com/problems/valid-sudoku/
 * Problem: Valid Sudoku
 *               
 */
#include <unordered_set>
#include <vector>
using std::unordered_set;
using std::vector;

class Solution {
 public:
   bool isValidSudoku(vector<vector<char> >& board) {
     unordered_set<int> uniq;
     for (int i = 0; i < ROW; ++i) {
       uniq.clear();
       for (int j = 0; j < COL; ++j) {
         char ch = board[i][j];
         if (ch == '.') {
           continue;
         }
         if (uniq.count(ch) > 0) {
           return false;
         }
         uniq.insert(ch);
       }
     }

     for (int j = 0; j < COL; ++j) {
       uniq.clear();
       for (int i = 0; i < ROW; ++i) {
         char ch = board[i][j];
         if (ch == '.') {
           continue;
         }
         if (uniq.count(ch) > 0) {
           return false;
         }
         uniq.insert(ch);
       }
     }

     for (int i = 0; i < ROW; i += 3) {
       for (int j = 0; j < COL; j += 3) {
         if (!isValidSubSudoku(board, i, j, i + 2, j + 2)) {
           return false;
         }
       }
     }

     return true;
   }

   bool isValidSubSudoku(vector<vector<char> >& board, int upper_left_row, int upper_left_col, int lower_right_row, int lower_right_col) {
     unordered_set<int> uniq;
     for (int i = upper_left_row; i <= lower_right_row; ++i) {
       for (int j = upper_left_col; j <= lower_right_col; ++j) {
         char ch = board[i][j];
         if (ch == '.') {
           continue;
         }
         if (uniq.count(ch) > 0) {
           return false;
         }
         uniq.insert(ch);
       }
     }
     return true;
   }

 private:
   static const int ROW = 9;
   static const int COL = 9;
};
