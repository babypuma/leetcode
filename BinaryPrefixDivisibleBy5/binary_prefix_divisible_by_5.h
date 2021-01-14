/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/14
 *
 * Source : https://leetcode-cn.com/problems/binary-prefix-divisible-by-5/
 * Problem: Binary Prefix Divisible By 5
 *               
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 public:
   vector<bool> prefixesDivBy5(vector<int>& A) {
     vector<bool> vec(A.size(), false);
     int sum = 0;
     for (int i = 0; i < A.size(); ++i) {
       sum <<= 1;
       sum += A[i];
       if (sum >= 5) {
         sum -= 5;
       }
       if (sum == 0) {
         vec[i] = true;
       }
     }

     return vec;
   }
};
