/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/15
 *
 * Source : https://leetcode-cn.com/problems/maximum-average-pass-ratio/
 * Problem: Maximum Average Pass Ratio
 *               
 */
#include <queue>
#include <vector>
using std::priority_queue;
using std::vector;

struct Elem {
  double delta;
  int p;
  int t;
  Elem() : delta(0.0), p(0), t(0) {}
  Elem(double d_, int p_, int t_) : delta(d_), p(p_), t(t_) {}
};

class Comparator {
 public:
   bool operator()(const Elem& e1, const Elem& e2) {
     return e1.delta < e2.delta;
   }
};

class Solution {
 public:
   double maxAverageRatio(vector<vector<int> >& classes, int extraStudents) {
     priority_queue<Elem, vector<Elem>, Comparator> que;
     double ans = 0.0;
     for (auto& c : classes) {
       int pass = c[0];
       int total = c[1];
       ans += static_cast<double>(pass) / total;
       que.push(Elem(diff(pass, total), pass, total));
     }

     for (int i = 0; i < extraStudents; ++i) {
       Elem elem = que.top();
       que.pop();
       ans += elem.delta;
       ++elem.p;
       ++elem.t;
       elem.delta = diff(elem.p, elem.t);
       que.push(elem);
     }

     return ans / classes.size();
   }

 private:
   double diff(int p, int t) {
     return static_cast<double>(p + 1) / (t + 1) - static_cast<double>(p) / t;
   }
};
