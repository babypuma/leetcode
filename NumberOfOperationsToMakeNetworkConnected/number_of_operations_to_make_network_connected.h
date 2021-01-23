/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/23
 *
 * Source : https://leetcode-cn.com/problems/number-of-operations-to-make-network-connected/
 * Problem: Number of Operations to Make Network Connected
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
   int makeConnected(int n, vector<vector<int> >& connections) {
     if (static_cast<int>(connections.size()) < n - 1) {
       return -1;
     }

     UF uf(n);
     for (auto& c : connections) {
       uf.union_(c[0], c[1]);
     }
     return uf.count() - 1;
   }
};
