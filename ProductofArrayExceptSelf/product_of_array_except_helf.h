/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/11/06
 *
 * Source : https://leetcode.com/problems/product-of-array-except-self/
 * Problem:	Product of Array Except Self
 *
 */
#include <vector>
using std::vector;

class Solution {
 public:
   vector<int> productExceptSelf(vector<int>& nums) {
     int n = nums.size();
     vector<int> prefix_product(n, 1);
     vector<int> suffix_product(n, 1);
     for (int i = 1; i < n; ++i) {
       prefix_product[i] = prefix_product[i - 1] * nums[i - 1];
     }
     for (int i = n - 2; i >= 0; --i) {
       suffix_product[i] = suffix_product[i + 1] * nums[i + 1];
     }
     for (int i = 0; i < n; ++i) {
       prefix_product[i] *= suffix_product[i];
     }
     return prefix_product;
   }
};
