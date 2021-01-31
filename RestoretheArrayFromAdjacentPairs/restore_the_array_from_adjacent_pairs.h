/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/31
 *
 * Source : https://leetcode-cn.com/problems/restore-the-array-from-adjacent-pairs/
 * Problem: Restore the Array From Adjacent Pairs
 *               
 */
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
 public:
   vector<int> restoreArray(vector<vector<int> >& adjacentPairs) {
     int sz = adjacentPairs.size() + 1;
     unordered_map<int, vector<int> > order_map;
     for (auto& v : adjacentPairs) {
       order_map[v[0]].push_back(v[1]);
       order_map[v[1]].push_back(v[0]);
     }
     vector<int> nums(sz);
     for (auto& [k, v] : order_map) {
       if (v.size() == 1) {
         nums[0] = k;
         nums[1] = v[0];
         break;
       }
     }
     for (int i = 2; i < sz; ++i) {
       int key = nums[i - 1];
       for (int j = 0; j < order_map[key].size(); ++j) {
         if (order_map[key][j] != nums[i - 2]) {
           nums[i] = order_map[key][j];
           break;
         }
       }
     }
     return nums;
   }
};
