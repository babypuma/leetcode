/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/09
 *
 * Source : https://leetcode-cn.com/problems/subarrays-with-k-different-integers/
 * Problem: Subarrays with K Different Integers
 *               
 */
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;

class Solution {
 public:
   int subarraysWithKDistinct(vector<int>& A, int K) {
     return atMostKDistinct(A, K) - atMostKDistinct(A, K - 1);
   }

 private:
   int atMostKDistinct(vector<int>& A, int K) {
     int sz = A.size();
     unordered_map<int, int> counter;
     int num = 0;
     int left = 0;
     int right = 0;
     while (right < sz) {
       ++counter[A[right]];
       ++right;
       while (counter.size() > K) {
         int tmp = A[left];
         ++left;
         if (--counter[tmp] == 0) {
           counter.erase(tmp);
         }
       }
       num += right - left;
     }
     return num;
   }
};
