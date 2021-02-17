/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/16
 *
 * Source : https://leetcode-cn.com/problems/array-partition-i/
 * Problem: Array Partition I
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int arrayPairSum(vector<int>& nums) {
     vector<int> vec(NUM, 0);
     for (auto& n : nums) {
       ++vec[n + OFFSET];
     }

     int sum = 0;
     bool skip = false;
     for (size_t i = 0; i < NUM; ++i) {
       if (vec[i] == 0) {
         continue;
       }
       int count = vec[i] - (skip ? 1 : 0);
       sum += ((count + 1) >> 1) * (i - OFFSET);
       skip = (count & 1 == 1);
     }

     return sum;
   }

 private:
   static const int NUM = 20001;
   static const int OFFSET = 10000;
};
