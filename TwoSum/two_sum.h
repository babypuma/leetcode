/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/08/31
 * Update : 2020/11/18
 *
 * Source : https://leetcode-cn.com/problems/two-sum/
 * Problem: Two Sum
 *               
 */
#include <vector>
#include <unordered_map>
#include <utility>
using std::vector;
using std::unordered_multimap;

class Solution {
 public:
   vector<int> twoSum(vector<int> &numbers, int target) { 
     vector<int> vec;
     unordered_multimap<int, int> mp;
     for (int i = 0; i < numbers.size(); ++i) {
       auto range = mp.equal_range(target - numbers[i]);
       for (auto it = range.first; it != range.second; ++it) {
         vec.push_back(it->second);
         vec.push_back(i);
         break;
       }
       if (!vec.empty()) {
         break;
       }
       mp.insert(std::pair<int, int>(numbers[i], i));
     }
     return vec;
   }
};
