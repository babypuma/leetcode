/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/09
 *
 * Source : https://leetcode.com/problems/number-of-islands/
 * Problem:	Number of Islands
 *
 */

#include <vector>
using std::vector;

class Solution {
 public:
   int numIslands(vector<vector<char> >& grid) {
     init(grid);
     for (size_t i = 0; i < row_; ++i) {
       for (size_t j = 0; j < column_; ++j) {
         if (grid[i][j] != '1') {
           continue;
         }
         if (i > 0 && grid[i - 1][j] == '1') {
           connect(i - 1, j, i, j);
         }
         if (j > 0 && grid[i][j - 1] == '1') {
           connect(i, j - 1, i, j);
         }
       }
     }

     return count();
   }

   void init(vector<vector<char> >& grid) {
     row_ = grid.size();
     column_ = grid.empty() ? 0 : grid[0].size();
     id_.clear();
     sz_.clear();
     id_.resize(row_ * column_);
     sz_.resize(row_ * column_);
     count_ = 0;
     for (size_t i = 0; i < row_; ++i) {
       for (size_t j = 0; j < column_; ++j) {
         int idx = getIndex(i, j);
         id_[idx] = idx;
         sz_[idx] = 1;
         if (grid[i][j] == '1') {
           count_++;
         }
       }
     }
   }

 private:
   int find(int i, int j) {
     int idx = getIndex(i, j);
     while (id_[idx] != idx) {
       idx = id_[idx];
     }
     return idx;
   }

   void connect(int i1, int j1, int i2, int j2) {
     int id1 = find(i1, j1);
     int id2 = find(i2, j2);
     if (id1 == id2) {
       return;
     }
     if (sz_[id1] > sz_[id2]) {
       id_[id2] = id_[id1];
       sz_[id1] += sz_[id2];
     } else {
       id_[id1] = id_[id2];
       sz_[id2] += sz_[id1];
     }
     count_--;
   }

   int count() {
     return count_;
   }

   int getIndex(int i, int j) {
     return i * column_ + j;
   }

 private:
   int row_;
   int column_;
   int count_;
   vector<int> id_;
   vector<int> sz_;
};
