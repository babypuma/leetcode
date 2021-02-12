/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/11
 *
 * Source : https://leetcode-cn.com/problems/jump-game-ii/
 * Problem: Jump Game II
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int jump(vector<int>& nums) {
     int sz = nums.size();
     if (sz == 1) {
       return 0;
     }

     int jump = 0;
     int max_index = 0;
     int next_max_index = 0;
     for (int i = 0; i <= max_index; ++i) {
       next_max_index = std::max(next_max_index, nums[i] + i);
       if (next_max_index >= sz - 1) {
         return jump + 1;
       }
       if (i == max_index) {
         max_index = next_max_index;
         ++jump;
       }
     }
     return jump;
   }
};
