/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/09
 *
 * Source : https://leetcode.com/problems/friend-circles/
 * Problem:	Friend Circles
 *
 */

#include <vector>
using std::vector;

class Solution {
 public:
   int findCircleNum(vector<vector<int> >& M) {
     init(M);
     for (size_t i = 0; i < stu_num_; ++i) {
       for (size_t j = i + 1; j < stu_num_; ++j) {
         if (M[i][j] == 1) {
           connect(i, j);
         }
       }
     }
     return count_;
   }

 private:
   void init(vector<vector<int> >& M) {
     stu_num_ = M.size();
     count_ = stu_num_;
     id_.clear();
     id_.resize(stu_num_);
     sz_.clear();
     sz_.resize(stu_num_);
     for (size_t i = 0; i < stu_num_; ++i) {
       id_[i] = i;
       sz_[i] = 1;
     }
   }

   int find(int p) {
     int id = id_[p];
     while (id != id_[id]) {
       id = id_[id];
     }
     return id;
   }

   void connect(int p, int q) {
     int id1 = find(p);
     int id2 = find(q);
     if (id1 == id2) {
       return;
     }
     if (sz_[id1] < sz_[id2]) {
       id_[id1] = id_[id2];
       sz_[id2] += sz_[id1];
     } else {
       id_[id2] = id_[id1];
       sz_[id1] += sz_[id2];
     }
     count_--;
   }

 private:
   int stu_num_;
   int count_;
   vector<int> id_;
   vector<int> sz_;
};
