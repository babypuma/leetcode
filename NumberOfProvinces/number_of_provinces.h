/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/07
 *
 * Source : https://leetcode-cn.com/problems/number-of-provinces/
 * Problem: Number of Provinces
 *               
 */
#include <vector>
using std::vector;

class UF {
 public:
   UF(vector<vector<int> >& matrix) {
     int n = matrix.size();
     cnt_ = n;
     id_.resize(n);
     for (int i = 0; i < n; ++i) {
       id_[i] = i;
     }
     vector<int>(n, 1).swap(sz_);
     for (int i = 0; i < n; ++i) {
       for (int j = 0; j < i; ++j) {
         if (matrix[i][j] == 1) {
           union_(i, j);
         }
       }
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
   int findCircleNum(vector<vector<int> >& isConnected) {
     UF uf(isConnected);
     return uf.count();
   }
};
