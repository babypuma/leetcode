/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/15
 *
 * Source : https://leetcode-cn.com/problems/most-stones-removed-with-same-row-or-column/
 * Problem: Most Stones Removed with Same Row or Column
 *               
 */
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class UF {
 public:
   UF() : cnt_(0) {
   }

   bool connected(int i, int j) {
     int p1 = find(i);
     int p2 = find(j);
     return p1 != -1 && p2 != -1 && p1 == p2;
   }

   void union_(int i, int j) {
     int r1 = find(i);
     if (r1 == -1) {
       id_[i] = i;
       sz_[i] = 1;
       ++cnt_;
     }

     int r2 = find(j);
     if (r2 == -1) {
       id_[j] = j;
       sz_[j] = 1;
       ++cnt_;
     }

     if (r1 != -1 && r2 != -1 && r1 == r2) {
       return;
     }

     r1 = find(i);
     r2 = find(j);
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
     if (id_.count(i) == 0) {
       return -1;
     }
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
   unordered_map<int, int> id_;
   unordered_map<int, int> sz_;
};

class Solution {
 public:
   int removeStones(vector<vector<int> >& stones) {
     UF uf;
     for (auto& stone : stones) {
       uf.union_(stone[0] + OFFSET, stone[1]);
     }
     return stones.size() - uf.count();
   }

 private:
   static const int OFFSET = 10001;
};
