/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/13
 *
 * Source : https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
 * Problem: Find All Numbers Disappeared in an Array
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   vector<int> findDisappearedNumbers(vector<int>& nums) {
     int sz = nums.size();
     for (int i = 0; i < sz; ++i) {
       int j = (nums[i] - 1) % sz;
       nums[j] += sz;
     }

     vector<int> dis;
     for (int i = 0; i < sz; ++i) {
       if (nums[i] <= sz) {
         dis.push_back(i + 1);
       }
     }
     return dis;
   }
};
