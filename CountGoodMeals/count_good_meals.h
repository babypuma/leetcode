/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/03
 *
 * Source : https://leetcode-cn.com/problems/count-good-meals/
 * Problem: Count Good Meals
 *               
 */
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
 public:
   int countPairs(vector<int>& deliciousness) {
     vector<int> binary_vec(EXP);
     binary_vec[0] = 1;
     for (int i = 1; i < EXP; ++i) {
       binary_vec[i] = binary_vec[i - 1] * 2;
     }

     unordered_map<int, int> delic_map;
     int count = 0;
     for (auto& delic : deliciousness) {
       vector<int>::iterator it = lower_bound(binary_vec.begin(), binary_vec.end(), delic);
       for (; it != binary_vec.end(); ++it) {
         unordered_map<int, int>::iterator iter = delic_map.find(*it - delic);
         if (iter != delic_map.end()) {
           if (MOD - count < iter->second) {
             count = iter->second - (MOD - count);
           } else {
             count += iter->second;
           }
         }
       }
       ++delic_map[delic];
     }

     return count;
   }

 private:
   static const int EXP = 22;
   static const int MOD = 1000000000 + 7;
};
