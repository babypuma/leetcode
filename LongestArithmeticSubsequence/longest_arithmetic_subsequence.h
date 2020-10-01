/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/30
 *
 * Source : https://leetcode-cn.com/problems/longest-arithmetic-subsequence/
 * Problem:	Longest Arithmetic Subsequence
 *
 */
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
 public:
   int longestArithSeqLength(vector<int>& A) {
     if (A.size() <= 2) {
       return A.size();
     }

     const int offset = 500;
     int max_len = 0;
     vector<vector<int> > len_map(1024, vector<int>(1024, 0));
     for (size_t i = 0; i < A.size(); ++i) {
       for (size_t j = 0; j < i; ++j) {
         int diff = A[i] - A[j] + offset;
         if (len_map[j][diff] > 0) {
           len_map[i][diff] = std::max(len_map[i][diff], len_map[j][diff] + 1);
         } else {
           len_map[i][diff] = 2;
         }
         max_len = std::max(max_len, len_map[i][diff]);
       }
     }

     return max_len;
   }
};
