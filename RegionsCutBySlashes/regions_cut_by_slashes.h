/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/25
 *
 * Source : https://leetcode-cn.com/problems/regions-cut-by-slashes/
 * Problem: Regions Cut By Slashes
 *               
 */
#include <string>
#include <vector>
using std::string;
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
   int regionsBySlashes(vector<string>& grid) {
     int sz = grid.size();
     UF uf(sz * sz * 2);
     for (int i = 0; i < sz; ++i) {
       for (int j = 0; j < sz; ++j) {
         char ch = grid[i][j];
         if (ch == '/') {
           if (i > 0) {
             if (grid[i - 1][j] == ' ' || grid[i - 1][j] == '\\') {
               uf.union_(getIndex(sz, i, j) * 2, getIndex(sz, i - 1, j) * 2);
             } else {
               uf.union_(getIndex(sz, i, j) * 2, getIndex(sz, i - 1, j) * 2 + 1);
             }
           }
           if (j > 0) {
             uf.union_(getIndex(sz, i, j) * 2, getIndex(sz, i, j - 1) * 2 + 1);
           }
         } else if (ch == '\\') {
           if (i > 0) {
             if (grid[i - 1][j] == ' ' || grid[i - 1][j] == '\\') {
               uf.union_(getIndex(sz, i, j) * 2 + 1, getIndex(sz, i - 1, j) * 2);
             } else {
               uf.union_(getIndex(sz, i, j) * 2 + 1, getIndex(sz, i - 1, j) * 2 + 1);
             }
           }
           if (j > 0) {
             uf.union_(getIndex(sz, i, j) * 2, getIndex(sz, i, j - 1) * 2 + 1);
           }
         } else if (ch == ' ') {
           uf.union_(getIndex(sz, i, j) * 2, getIndex(sz, i, j) * 2 + 1);
           if (i > 0) {
             if (grid[i - 1][j] == ' ' || grid[i - 1][j] == '\\') {
               uf.union_(getIndex(sz, i, j) * 2 + 1, getIndex(sz, i - 1, j) * 2);
             } else {
               uf.union_(getIndex(sz, i, j) * 2 + 1, getIndex(sz, i - 1, j) * 2 + 1);
             }
           }
           if (j > 0) {
             uf.union_(getIndex(sz, i, j) * 2, getIndex(sz, i, j - 1) * 2 + 1);
           }
         }
       }
     }

     return uf.count();
   }

 private:
   int getIndex(int sz, int i, int j) {
     return sz * i + j;
   }
};
