/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/29
 *
 * Source : https://leetcode-cn.com/problems/surrounded-regions/
 * Problem: Surrounded Regions
 *               
 */
#include <vector>
using std::vector;

class UF {
 public:
   UF(int n) : cnt_(n), id_(n), sz_(n, 1) {
     int idx = 0;
     for (auto& id : id_) {
       id = idx++;
     }
   }

   bool connected(int i, int j) {
     return find(i) == find(j);
   }

   void union_(int i, int j) {
     int r1 = find(i);
     int r2 = find(j);
     if (r1 == r2) {
       return;
     }
     if (sz_[r1] < sz_[r2]) {
       id_[r1] = r2;
       sz_[r2] += sz_[r1];
     } else {
       id_[r2] = r1;
       sz_[r1] += sz_[r2];
     }
     --cnt_;
   }

   int find(int i) {
     int r = i;
     while (r != id_[r]) {
       r = id_[r];
     }
     return r;
   }

   int count() {
     return cnt_;
   }

 private:
   int cnt_;
   vector<int> id_;
   vector<int> sz_;
};

class Solution {
 public:
   void solve(vector<vector<char> >& board) {
     if (board.empty() || board[0].empty()) {
       return;
     }
     int row = board.size();
     int col = board[0].size();
     const int virtual_index = row * col;
     UF uf(row * col + 1);
     for (int i = 0; i < row; ++i) {
       for (int j = 0; j < col; ++j) {
         if (board[i][j] == 'X') {
           continue;
         }
         int idx = getIndex(col, i, j);
         if (i == 0 || i == row - 1 || j == 0 || j == col - 1) {
           uf.union_(idx, virtual_index);
         }
         if (i > 0 && board[i - 1][j] == 'O') {
           uf.union_(idx, getIndex(col, i - 1, j));
         }
         if (j > 0 && board[i][j - 1] == 'O') {
           uf.union_(idx, getIndex(col, i, j - 1));
         }
       }
     }
     for (int i = 1; i < row - 1; ++i) {
       for (int j = 1; j < col - 1; ++j) {
         if (board[i][j] == 'X') {
           continue;
         }
         int idx = getIndex(col, i, j);
         if (!uf.connected(idx, virtual_index)) {
           board[i][j] = 'X';
         }
       }
     }
   }

 private:
   int getIndex(int col, int i, int j) {
     return i * col + j;
   }
};
