/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/08/31
 * Update : 2020/12/07
 *
 * Source : https://leetcode-cn.com/problems/container-with-most-water/
 * Problem:	Container With Most Water
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int maxArea(vector<int>& height) {
     int left = 0;
     int right = height.size() - 1;
     int ans = 0;
     while (left < right) {
       ans = std::max(ans, std::min(height[left], height[right]) * (right - left));
       height[left] <= height[right] ? ++left : --right;
     }
     return ans;
   }
};
