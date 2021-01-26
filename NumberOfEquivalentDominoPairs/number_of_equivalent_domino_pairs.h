/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/26
 *
 * Source : https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs/
 * Problem: Number of Equivalent Domino Pairs
 *               
 */
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;

class Solution {
 public:
   int numEquivDominoPairs(vector<vector<int> >& dominoes) {
     int num = 0;
     unordered_map<int, int> counter;
     for (auto& d : dominoes) {
       int enc = (d[0] < d[1]) ? (d[0] * 10 + d[1]) : (d[1] * 10 + d[0]);
       if (counter.count(enc) > 0) {
         num += counter[enc];
       }
       ++counter[enc];
     }
     return num;
   }
};
