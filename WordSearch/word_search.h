/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/01
 *
 * Source : https://leetcode.com/problems/word-search/
 * Problem:	Word Search
 *
 */
#include <vector>
#include <string>
#include <unordered_set>

using std::vector;
using std::string;

class Solution {
 public:
   bool exist(vector<vector<char> >& board, string word) {
     bool done = false;
     std::unordered_set<int32_t> visited_cell;
     for (size_t i = 0; i < board[0].size(); ++i) {
       for (size_t j = 0; j < board.size(); ++j) {
         backtrack(board, i, j, word, 0, visited_cell, done);
         if (done) {
           return done;
         }
       }
     }
     return done;
   }

 private:
   void backtrack(vector<vector<char> >& board, int horizonal_idx, int vertical_idx, const string& word, size_t pos, std::unordered_set<int32_t>& visited_cell, bool& done) {
     if (pos >= word.size()) {
       done = true;
     }
     if (done) {
       return;
     }
     if (horizonal_idx < 0 || horizonal_idx >= static_cast<int>(board[0].size())) {
       return;
     }
     if (vertical_idx < 0 || vertical_idx >= static_cast<int>(board.size())) {
       return;
     }
     int32_t key = getKey(horizonal_idx, vertical_idx);
     if (visited_cell.find(key) != visited_cell.end()) {
       return;
     }
     if (board[vertical_idx][horizonal_idx] == word[pos]) {
       visited_cell.insert(key);
       backtrack(board, horizonal_idx + 1, vertical_idx, word, pos + 1, visited_cell, done);
       backtrack(board, horizonal_idx - 1, vertical_idx, word, pos + 1, visited_cell, done);
       backtrack(board, horizonal_idx, vertical_idx + 1, word, pos + 1, visited_cell, done);
       backtrack(board, horizonal_idx, vertical_idx - 1, word, pos + 1, visited_cell, done);
       visited_cell.erase(key);
     }
   }
  
   int32_t getKey(int high, int low) {
     return ((high & 0xFFFF) << 16) | (low & 0xFFFF);
   }
};
