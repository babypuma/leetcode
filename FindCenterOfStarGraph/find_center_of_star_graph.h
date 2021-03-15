/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/15
 *
 * Source : https://leetcode-cn.com/problems/find-center-of-star-graph/
 * Problem: Find Center of Star Graph
 *               
 */
#include <unordered_set>
#include <vector>
using std::unordered_set;
using std::vector;

class Solution {
 public:
   int findCenter(vector<vector<int> >& edges) {
     unordered_set<int> uniq;
     int center = 0;
     for (auto& e : edges) {
       int u = e[0];
       int v = e[1];
       if (uniq.count(u) > 0) {
         center = u;
         break;
       }
       uniq.insert(u);
       if (uniq.count(v) > 0) {
         center = v;
         break;
       }
       uniq.insert(v);
     }
     return center;
   }
};
