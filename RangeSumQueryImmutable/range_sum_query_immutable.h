/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/29
 *
 * Source : https://leetcode-cn.com/problems/range-sum-query-immutable/
 * Problem:	Range Sum Query - Immutable
 *
 */
#include <vector>
using std::vector;

class NumArray {
 public:
   NumArray(vector<int>& nums) : vec(nums.size() + 1, 0) {
     for (size_t i = 1; i < vec.size(); ++i) {
       vec[i] = vec[i - 1] + nums[i - 1];
     }
   }

   int sumRange(int i, int j) {
     return vec[j + 1] - vec[i];
   }

 private:
   vector<int> vec;
};
