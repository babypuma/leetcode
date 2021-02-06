/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/06
 *
 * Source : https://leetcode-cn.com/problems/bricks-falling-when-hit/
 * Problem: Bricks Falling When Hit
 *               
 */
#include <vector>
#include <unordered_set>
using std::vector;
using std::unordered_set;

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

   int group_size(int i) {
     int p = find(i);
     return p < sz_.size() ? sz_[p] : 0;
   }

 private:
   int cnt_;
   vector<int> id_;
   vector<int> sz_;
};

class Solution {
 public:
   vector<int> hitBricks(vector<vector<int> >& grid, vector<vector<int> >& hits) {
     unordered_set<int32_t> hits_set;
     for (auto& h : hits) {
       hits_set.insert(h[0] << 16 | h[1]);
     }

     int row = grid.size();
     int col = grid[0].size();
     UF uf(row * col + 1);
     for (size_t i = 0; i < row; ++i) {
       for (size_t j = 0; j < col; ++j) {
         if (grid[i][j] == 0) {
           continue;
         }
         if (hits_set.count(i << 16 | j) != 0) {
           continue;
         }

         // connected with the virtual node
         int idx = i * col + j;
         if (i == 0) {
           uf.union_(row * col, idx);
         }
         if (i > 0 && grid[i - 1][j] == 1 && hits_set.count((i - 1) << 16 | j) == 0) {
           uf.union_(idx, idx - col);
         }
         if (j > 0 && grid[i][j - 1] == 1 && hits_set.count(i << 16 | (j - 1)) == 0) {
           uf.union_(idx, idx - 1);
         }
       }
     }

     int sz = hits.size();
     vector<int> bricks(sz, 0);
     int prev_num = uf.group_size(row * col);
     for (int k = sz - 1; k >= 0; --k) {
       int i = hits[k][0];
       int j = hits[k][1];
       addBrick(uf, grid, row, col, hits_set, i, j);
       int curr_num = uf.group_size(row * col);
       bricks[k] = (curr_num == prev_num) ? 0 : curr_num - prev_num - 1;
       prev_num = curr_num;
     }

     return bricks;
   }

 private:
   void addBrick(UF& uf, vector<vector<int> >& grid, int row, int col, unordered_set<int32_t>& hits_set, int i, int j) {
     if (grid[i][j] == 0) {
       return;
     }

     int idx = i * col + j;
     if (i == 0) {
       uf.union_(row * col, idx);
     } else if (grid[i - 1][j] == 1 && hits_set.count((i - 1) << 16 | j) == 0) {
       uf.union_(idx - col, idx);
     }
     if (i < row - 1 && grid[i + 1][j] == 1 && hits_set.count((i + 1) << 16 | j) == 0) {
       uf.union_(idx + col, idx);
     }

     if (j > 0 && grid[i][j - 1] == 1 && hits_set.count(i << 16 | (j - 1)) == 0) {
       uf.union_(idx - 1, idx);
     }
     if (j < col - 1 && grid[i][j + 1] == 1 && hits_set.count(i << 16 | (j + 1)) == 0) {
       uf.union_(idx + 1, idx);
     }
     hits_set.erase(i << 16 | j);
   }
};
