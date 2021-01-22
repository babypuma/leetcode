/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/22
 *
 * Source : https://leetcode-cn.com/problems/tuple-with-same-product/
 * Problem: Tuple with Same Product
 *               
 */
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
 public:
   int tupleSameProduct(vector<int>& nums) {
     unordered_map<int, int> product;
     for (int i = 0; i < nums.size() - 1; ++i) {
       for (int j = i + 1; j < nums.size(); ++j) {
         ++product[nums[i] * nums[j]];
       }
     }
     int count = 0;
     for (auto& [k, v] : product) {
       if (v > 1) {
         count += v * (v - 1) * 4;
       }
     }
     return count;
   }
};
