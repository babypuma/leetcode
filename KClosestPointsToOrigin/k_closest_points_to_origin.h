/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/02
 *
 * Source : https://leetcode-cn.com/problems/k-closest-points-to-origin/
 * Problem: K Closest Points to Origin
 *               
 */
#include <vector>
#include <cmath>
using std::vector;

class Solution {
 public:
   struct DistElem {
     double dist;
     size_t index;
     DistElem(double d, size_t i) : dist(d), index(i) {
     }
   };

   vector<vector<int> > kClosest(vector<vector<int> >& points, int K) {
     vector<DistElem> dists;
     for (size_t i = 0; i < points.size(); ++i) {
       int x = points[i][0];
       int y = points[i][1];
       dists.push_back(DistElem(sqrt(x * x + y * y), i));
     }

     int left = 0;
     int right = dists.size() - 1;
     int n = partition(dists, left, right);
     while (n != K - 1) {
       if (n > K - 1) {
         right = n - 1;
       } else {
         left = n + 1;
       }
       n = partition(dists, left, right);
     }

     vector<vector<int> > vec2d;
     for (size_t i = 0; i <= n; ++i) {
       vec2d.push_back(points[dists[i].index]);
     }

     return vec2d;
   }

 private:
   int partition(vector<DistElem>& dists, int left, int right) {
     if (left == right) {
       return left;
     }

     int v = right;
     int l = left - 1;
     int r = right;
     for (;;) {
       while (dists[++l].dist < dists[v].dist) {
       }
       while (dists[v].dist < dists[--r].dist) {
         if (r == left) {
           break;
         }
       }
       if (l >= r) {
         break;
       }
       swap(dists[l], dists[r]);
     }
     swap(dists[l], dists[v]);
     return l;
   }

   void swap(DistElem& d1, DistElem& d2) {
     DistElem temp = d1;
     d1 = d2;
     d2 = temp;
   }
};
