/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/20
 *
 * Source : https://leetcode-cn.com/problems/evaluate-division/
 * Problem: valuate Division
 *               
 */
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;

class UF {
 public:
  void union_(string& s1, string& s2, double w) {
    string p1 = find(s1);
    string p2 = find(s2);
    if (p1 == p2) {
      return;
    }
    double w1 = weightToParent(s1);
    parent_[p1] = s2;
    weight_[p1] = w / w1;
  }

  string find(string& s) {
    string p = s;
    while (parent_.count(p) != 0) {
      p = parent_[p];
    }
    return p;
  }

  bool connected(string& s1, string& s2) {
    return find(s1) == find(s2);
  }

  double weightToParent(string& s) {
    double w = 1.0;
    string p = s;
    while (parent_.count(p) != 0) {
      w *= weight_[p];
      p = parent_[p]; 
    }
    return w;
  }

 private:
  unordered_map<string, string> parent_;
  unordered_map<string, double> weight_;
};

class Solution {
 public:
   vector<double> calcEquation(vector<vector<string> >& equations, vector<double>& values, vector<vector<string> >& queries) {
     UF uf;
     unordered_set<string> occurred;
     for (size_t i = 0; i < equations.size(); ++i) {
       vector<string>& e = equations[i];
       uf.union_(e[0], e[1], values[i]);
       occurred.insert(e[0]);
       occurred.insert(e[1]);
     }

     vector<double> vec;
     for (auto& q : queries) {
       if (occurred.count(q[0]) == 0 || occurred.count(q[1]) == 0) {
         vec.push_back(-1.0);
         continue;
       }
       if (q[0] == q[1]) {
         vec.push_back(1.0);
         continue;
       }
       string p1 = uf.find(q[0]);
       string p2 = uf.find(q[1]);
       if (p1 != p2) {
         vec.push_back(-1.0);
         continue;
       }
       double w1 = uf.weightToParent(q[0]);
       double w2 = uf.weightToParent(q[1]);
       vec.push_back(w1 / w2);
     }
     return vec;
   }
};
