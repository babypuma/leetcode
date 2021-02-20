/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/20
 *
 * Source : https://leetcode-cn.com/problems/degree-of-an-array/
 * Problem: Degree of an Array
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int findShortestSubArray(vector<int>& nums) {
     vector<int> freq(NUM, 0);
     vector<int> left(NUM, -1);
     int degree = 0;
     int ans = 0;
     int sz = nums.size();
     for (int i = 0; i < sz; ++i) {
       int idx = nums[i];
       ++freq[idx];
       if (left[idx] == -1) {
         left[idx] = i;
       }

       if (freq[idx] > degree) {
         degree = freq[idx];
         ans = i - left[idx] + 1;
       } else if (freq[idx] == degree) {
         ans = std::min(ans, i - left[idx] + 1);
       }
     }
     return ans;
   }

 private:
   static const int NUM = 50000;
};
