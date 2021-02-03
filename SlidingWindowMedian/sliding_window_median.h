/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/03
 *
 * Source : https://leetcode-cn.com/problems/sliding-window-median/
 * Problem: Sliding Window Median
 *               
 */
#include <vector>
#include <set>
using std::vector;
using std::multiset;

class Solution {
 public:
   vector<double> medianSlidingWindow(vector<int>& nums, int k) {
     multiset<double> window;
     vector<double> m;
     for (int i = 0; i < nums.size(); ++i) {
       if (i >= k) {
         window.erase(window.find(nums[i - k]));
       }
       window.insert(nums[i]);
       if (i >= k - 1) {
         auto it = window.begin();
         std::advance(it, (k - 1) / 2);
         m.push_back((*it + *next(it, 1 - k % 2)) / 2.0);
       }
     }
  
     return m;
   }
};
