/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/18
 *
 * Source : https://leetcode-cn.com/problems/accounts-merge/
 * Problem: Accounts Merge
 *               
 */
#include <string>
#include <vector>
#include <unordered_map>
using std::string;
using std::vector;
using std::unordered_map;

class UF {
 public:
   UF(int n) : cnt_(n), id_(n), sz_(n, 1) {
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
   vector<vector<string> > accountsMerge(vector<vector<string> >& accounts) {
     UF uf(accounts.size());
     unordered_map<string, int> acc_map;
     for (size_t i = 0; i < accounts.size(); ++i) {
       for (size_t j = 1; j < accounts[i].size(); ++j) {
         if (acc_map.count(accounts[i][j]) != 0) {
           uf.union_(acc_map[accounts[i][j]], i);
         } else {
           acc_map[accounts[i][j]] = i;
         }
       }
     }

     vector<vector<string> > merged_acc;
     unordered_map<int, int> parent_idx;
     for (auto& acc : acc_map) {
       int parent = uf.find(acc.second);
       if (parent_idx.count(parent) != 0) {
         merged_acc[parent_idx[parent]].push_back(acc.first);
       } else {
         parent_idx[parent] = merged_acc.size();
         merged_acc.push_back(vector<string>());
         merged_acc.back().push_back(accounts[parent][0]);
         merged_acc.back().push_back(acc.first);
       }
     }

     for (auto& acc : merged_acc) {
       std::sort(acc.begin() + 1, acc.end());
     }

     return merged_acc;
   }
};
