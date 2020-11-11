/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/09
 * Update : 2020/11/11
 *
 * Source : https://leetcode.com/problems/number-of-islands/
 * Problem:	Number of Islands
 *
 */

#include <vector>
using std::vector;

class UF {
 public:
  UF(vector<vector<char> >& grid) {
    row_ = grid.size();
    col_ = (row_ > 0) ? grid[0].size() : 0;
    num_ = 0;
    sz_.reserve(row_ * col_);
    id_.reserve(row_ * col_);
    for (int i = 0; i < row_; ++i) {
      for (int j = 0; j < col_; ++j) {
        int idx = col_ * i + j;
        if (grid[i][j] == '1') {
          sz_.push_back(1);
          ++num_;
        } else {
          sz_.push_back(0);
        }
        id_.push_back(idx);
      }
    }
  }

  int find(int idx) {
    int p = id_[idx];
    while (p != id_[p]) {
      p = id_[p];
    }
    return p;
  }

  void union_(int a, int b) {
    int p1 = find(a);
    int p2 = find(b);
    if (p1 == p2) {
      return;
    }
    if (sz_[p1] < sz_[p2]) {
      id_[p1] = p2;
      sz_[p2] += sz_[p1];
    } else {
      id_[p2] = p1;
      sz_[p1] += sz_[p2];
    }
    --num_;
  }

  int count() {
    return num_;
  }

 private:
  int row_;
  int col_;
  int num_;
  vector<int> sz_;
  vector<int> id_;
};

class Solution {
 public:
   int numIslands(vector<vector<char> >& grid) {
     UF uf(grid);
     int row = grid.size();
     int col = (row > 0) ? grid[0].size() : 0;
     for (int i = 0; i < row; ++i) {
       for (int j = 0; j < col; ++j) {
         if (grid[i][j] == '1') {
           int idx = i * col + j;
           if (i > 0 && grid[i - 1][j] == '1') {
             uf.union_(idx, idx - col);
           }
           if (j > 0 && grid[i][j - 1] == '1') {
             uf.union_(idx, idx - 1);
           }
         }
       }
     }

     return uf.count();
   }
};
