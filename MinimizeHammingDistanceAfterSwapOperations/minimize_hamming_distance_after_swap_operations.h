/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/14
 *
 * Source : https://leetcode-cn.com/problems/minimize-hamming-distance-after-swap-operations/
 * Problem: Minimize Hamming Distance After Swap Operations
 *               
 */
#include <unordered_map>
#include <unordered_set>
#include <vector>
using std::vector;
using std::unordered_map;
using std::unordered_multiset;

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
   int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int> >& allowedSwaps) {
     UF uf(NUM);
     for (auto& s : allowedSwaps) {
       uf.union_(s[0], s[1]);
     }

     // index->multiset<val>
     unordered_map<int, unordered_multiset<int> > source_vmap;
     unordered_map<int, unordered_multiset<int> > target_vmap;
     for (size_t i = 0; i < source.size(); ++i) {
       int p = uf.find(i);
       source_vmap[p].insert(source[i]);
       target_vmap[p].insert(target[i]);
     }

     int dist = 0;
     for (size_t i = 0; i < source.size(); ++i) {
       if (source_vmap.count(i) == 0) {
         continue;
       }
       for (auto& v : source_vmap[i]) {
         auto it = target_vmap[i].find(v);
         if (it == target_vmap[i].end()) {
           ++dist;
         } else {
           target_vmap[i].erase(it);
         }
       }
     }

     return dist;
   }

 private:
   static const int NUM = 100000;
};
