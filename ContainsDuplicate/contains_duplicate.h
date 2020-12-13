/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/13
 *
 * Source : https://leetcode-cn.com/problems/contains-duplicate/
 * Problem:	Contains Duplicate
 *               
 */
#include <unordered_set>
#include <vector>
using std::unordered_set;
using std::vector;

class Solution {
 public:
   bool containsDuplicate(vector<int>& nums) {
     unordered_set<int> num_set;
     for (size_t i = 0; i < nums.size(); ++i) {
       if (num_set.find(nums[i]) != num_set.end()) {
         return true;
       }
       num_set.insert(nums[i]);
     }
     return false;
   }
};
