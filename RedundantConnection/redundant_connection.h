/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/13
 *
 * Source : https://leetcode-cn.com/problems/redundant-connection/
 * Problem: Redundant Connection
 *               
 */
#include <vector>
using std::vector;

class UF {
 public:
   UF(int n) : parent_(n), sz_(n, 1) {
     for (int i = 0; i < n; ++i) {
       parent_[i] = i;
     }
   }

   void union_(int i, int j) {
     int p1 = find(i);
     int p2 = find(j);
     if (p1 == p2) {
       return;
     }
     if (sz_[p1] < sz_[p2]) {
       parent_[p1] = p2;
       sz_[p2] += sz_[p1];
     } else {
       parent_[p2] = p1;
       sz_[p1] += sz_[p2];
     }
   }

   int find(int i) {
     int p = i;
     while (p != parent_[p]) {
       p = parent_[p];
     }
     return p;
   }

   bool connected(int i, int j) {
     return find(i) == find(j);
   }

 private:
   vector<int> parent_;
   vector<int> sz_;
};

class Solution {
 public:
   vector<int> findRedundantConnection(vector<vector<int> >& edges) {
     UF uf(edges.size() + 1);
     for (auto& e : edges) {
       if (uf.connected(e[0], e[1])) {
         return e;
       }
       uf.union_(e[0], e[1]);
     }
     return edges.back();
   }
};
