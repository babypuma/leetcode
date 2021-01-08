/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/03/18
 * Update : 2021/01/08
 *
 * Source : https://leetcode-cn.com/problems/3sum-closest/
 * Problem: 3Sum Closest
 *               
 */
#include <algorithm>
#include <vector>
using std::vector;

class Solution {
 public:
   int threeSumClosest(vector<int> &num, int target) {
     int sum = num[0] + num[1] + num[2];
     std::sort(num.begin(), num.end());
     for (int i = 0; i < num.size() - 2; ++i) {
       int n1 = num[i];
       int left = i + 1;
       int right = num.size() - 1;
       while (left < right) {
         if (num[left] + num[right] + n1 == target) {
           sum = target;
           break;
         }

         if (std::abs(target - (num[left] + num[right] + n1)) < std::abs(target - sum)) {
           sum = num[left] + num[right] + n1;
         }

         if (num[left] + num[right] + n1 < target) {
           ++left;
         } else {
           --right;
         }
       }
     }
     return sum;
   }
};
