/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/11
 *
 * Source : https://leetcode-cn.com/problems/smallest-string-with-swaps/
 * Problem: Smallest String With Swaps
 *               
 */
#include <string>
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::string;
using std::vector;

class UF {
 public:
   UF(int n) : cnt_(n), id_(n), sz_(n, 1) {
     cnt_ = n;
     for (int i = 0; i < n; ++i) {
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
     int r = i;
     while (r != id_[r]) {
       r = id_[r];
     }
     return r;
   }

   int count() {
     return cnt_;
   }

   int findUnionSize(int i) {
     int p = find(i);
     return sz_[p];
   }

 private:
   int cnt_;
   vector<int> id_;
   vector<int> sz_;
};

class LetterCommunity {
 public:
   LetterCommunity() : count_(0), min_idx_(SZ), comm_(SZ, 0) {
   }

   void add(char ch) {
     ++count_;
     int idx = ch - 'a';
     if (idx < min_idx_) {
       min_idx_ = idx;
     }
     ++comm_[idx];
   }

   char getMin() {
     char ch = min_idx_ + 'a';
     if (--comm_[min_idx_] == 0) {
       while (min_idx_ < SZ && comm_[min_idx_] == 0) {
         ++min_idx_;
       }
     }
     --count_;
     return ch;
   }

   bool empty() {
     return count_ == 0;
   }

 private:
   static const int SZ = 26;
   int count_;
   int min_idx_;
   vector<int> comm_;
};

class Solution {
 public:
   string smallestStringWithSwaps(string s, vector<vector<int> >& pairs) {
     // build UF
     UF uf(s.size());
     for (auto& p : pairs) {
       uf.union_(p[0], p[1]);
     }

     // build Letter Community
     unordered_map<int, LetterCommunity> lc_map;
     for (size_t i = 0; i < s.size(); ++i) {
       if (uf.findUnionSize(i) == 1) {
         continue;
       }
       int parent = uf.find(i);
       lc_map[parent].add(s[i]);
     }

     // reorder string
     string target;
     for (size_t i = 0; i < s.size(); ++i) {
       int parent = uf.find(i);
       if (lc_map.count(parent) == 0) {
         target += s[i];
         continue;
       }
       target += lc_map[parent].getMin();
     }

     return target;
   }
};
