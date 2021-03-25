/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/25
 *
 * Source : https://leetcode-cn.com/problems/valid-mountain-array/
 * Problem: Valid Mountain Array
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   bool validMountainArray(vector<int>& arr) {
     int sz = arr.size();
     int i = 1;
     for (; i < sz; ++i) {
       if (arr[i] == arr[i - 1]) {
         return false;
       } else if (arr[i] < arr[i - 1]) {
         break;
       }
     }
     if (i == 1 || i == sz) {
       return false;
     }
     for (; i < sz; ++i) {
       if (arr[i] >= arr[i - 1]) {
         return false;
       }
     }
     return true;
   }
};
