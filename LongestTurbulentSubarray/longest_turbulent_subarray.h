/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/08
 *
 * Source : https://leetcode-cn.com/problems/longest-turbulent-subarray/
 * Problem: Longest Turbulent Subarray
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int maxTurbulenceSize(vector<int>& arr) {
     int sz = arr.size();
     int ans = 1;
     int left = 0;
     int right = 0;
     while (right < sz - 1) {
       if (left == right) {
         if (arr[left] == arr[left + 1]) {
           ++left;
         }
         ++right;
       } else if ((arr[right - 1] < arr[right] && arr[right] > arr[right + 1]) ||
                  (arr[right - 1] > arr[right] && arr[right] < arr[right + 1])) {
         ++right;
       } else {
         left = right;
       }
       ans = std::max(ans, right - left + 1);
     }
     return ans;
   }
};
