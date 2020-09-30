/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/30
 *
 * Source : https://leetcode-cn.com/problems/length-of-longest-fibonacci-subsequence/
 * Problem:	Length of Longest Fibonacci Subsequence
 *
 */
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
 public:
   int lenLongestFibSubseq(vector<int>& A) {
     unordered_map<int, int> idx_map;
     for (size_t i = 0; i < A.size(); ++i) {
       idx_map[A[i]] = i;
     }

     int max_len = 0;
     unordered_map<int64_t, int32_t> len_map;
     for (int64_t i = 0; i < A.size(); ++i) {
       for (int64_t j = 0; j < i; ++j) {
         int val = A[i] - A[j];
         if (val < A[j] && idx_map.count(val)) {
           len_map[(i << 32) | j] = std::max(len_map[(i << 32) | j], len_map[(j << 32) | idx_map[val]] + 1);
           max_len = std::max(max_len, len_map[(i << 32) | j]);
         }
       }
     }

     return max_len > 0 ? max_len + 2 : 0;
   }
};
