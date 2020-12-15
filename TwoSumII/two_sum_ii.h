/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/16
 *
 * Source : https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
 * Problem: Two Sum II - Input array is sorted
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   vector<int> twoSum(vector<int>& numbers, int target) {
     vector<int> vec;
     int i = 0;
     int j = numbers.size() - 1;
     while (i < j) {
       int sum = numbers[i] + numbers[j];
       if (sum == target) {
         vec.push_back(i + 1);
         vec.push_back(j + 1);
         break;
       }

       if (sum < target) {
         ++i;
       } else {
         --j;
       }
     }

     return vec;
   }
};
