/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/04
 *
 * Source : https://leetcode-cn.com/problems/sliding-window-maximum/
 * Problem: Sliding Window Maximum
 *
 */
#include <vector>
#include <deque>
using std::vector;
using std::deque;

class Solution {
 public:
   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     deque<int> deq;
     int i = 0;
     for (; i < k; ++i) {
       while (!deq.empty() && nums[deq.back()] <= nums[i]) {
         deq.pop_back();
       }
       deq.push_back(i);
     }

     vector<int> vec;
     vec.push_back(nums[deq.front()]);
     for (; i < nums.size(); ++i) {
       while (!deq.empty() && nums[deq.back()] <= nums[i]) {
         deq.pop_back();
       }
       deq.push_back(i);

       while (deq.front() + k - 1 < i) {
         deq.pop_front();
       }
       vec.push_back(nums[deq.front()]);
     }

     return vec;
   }
};
