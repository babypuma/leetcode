/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/27
 *
 * Source : https://leetcode-cn.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
 * Problem: Remove Max Number of Edges to Keep Graph Fully Traversable
 *               
 */
#include <vector>
using std::vector;

class UF {
 public:
   UF(int cnt) : cnt_(cnt), id_(cnt_), sz_(cnt_, 1) {
     for (int i = 0; i < cnt_; ++i) {
       id_[i] = i;
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
     int p = i;
     while (p != id_[p]) {
       p = id_[p];
     }
     return p;
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
   int maxNumEdgesToRemove(int n, vector<vector<int> >& edges) {
     int sz = edges.size();
     if (sz < n - 1) {
       return -1;
     }
     UF uf1(n);
     UF uf2(n);
     int num = 0;
     for (auto& e : edges) {
       if (e[0] != 3) {
         continue;
       }
       int i = e[1] - 1;
       int j = e[2] - 1;
       if (uf1.connected(i, j)) {
         continue;
       }
       uf1.union_(i, j);
       uf2.union_(i, j);
       ++num;
     }
     for (auto& e : edges) {
       if (e[0] == 3) {
         continue;
       }
       int i = e[1] - 1;
       int j = e[2] - 1;
       if (e[0] == 1) {
         if (uf1.connected(i, j)) {
           continue;
         }
         uf1.union_(i, j);
         ++num;
       } else if (e[0] == 2) {
         if (uf2.connected(i, j)) {
           continue;
         }
         uf2.union_(i, j);
         ++num;
       }
     }

     if (uf1.count() > 1 || uf2.count() > 1) {
       return -1;
     }
     return sz - num;
   }
};
