/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/11/06
 *
 * Source : https://leetcode-cn.com/problems/find-two-non-overlapping-sub-arrs-each-with-target-sum/
 * Problem:	Find Two Non-overlapping Sub-arrs Each With Target Sum
 *
 */
#include <vector>
#include <map>
using std::vector;
using std::multimap;

class Solution {
 public:
   int minSumOfLengths(vector<int>& arr, int target) {
     multimap<int, int> len_map;
     int left = 0;
     int right = 0;
     int sum = 0;
     while (right < arr.size()) {
       sum += arr[right];
       ++right;
       if (sum < target) {
         continue;
       }
       while (sum > target) {
         sum -= arr[left];
         ++left;
       }
       if (sum == target) {
         len_map.insert(std::pair<int, int>(right - left, left));
       }
     }
     return findMinSum(len_map);
   }
   
 private:
   int findMinSum(multimap<int, int>& len_map) {
     int ans = INT_MAX;
     for (auto it = len_map.begin(); it != len_map.end(); ++it) {
       if (it->first * 2 >= ans) {
         break;
       }
       auto it2 = it;
       while ((++it2) != len_map.end()) {
         if (it->second < it2->second && it->second + it->first > it2->second ||
             it2->second < it->second && it2->second + it2->first > it->second) {
           continue;
         }
         ans = std::min(ans, it->first + it2->first);
         break;
       }
     }
     return ans == INT_MAX ? -1 : ans;
   }
};
