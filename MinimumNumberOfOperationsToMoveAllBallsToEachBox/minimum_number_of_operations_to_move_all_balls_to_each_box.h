/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/21
 *
 * Source : https://leetcode-cn.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
 * Problem: Minimum Number of Operations to Move All Balls to Each Box
 *               
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 public:
   vector<int> minOperations(string boxes) {
     int sz = boxes.size();
     vector<int> prefix_sum(sz, 0);
     vector<int> prefix_count(sz, 0);
     for (int i = 1; i < sz; ++i) {
       bool has = (boxes[i - 1] == '1');
       prefix_sum[i] = prefix_sum[i - 1] + (has ? i : 0);
       prefix_count[i] = prefix_count[i - 1] + (has ? 1 : 0);
     }

     vector<int> suffix_sum(sz, 0);
     vector<int> suffix_count(sz, 0);
     for (int i = sz - 2; i >= 0; --i) {
       bool has = (boxes[i + 1] == '1');
       suffix_sum[i] = suffix_sum[i + 1] + (has ? i + 2 : 0);
       suffix_count[i] = suffix_count[i + 1] + (has ? 1 : 0);
     }

     vector<int> ops(sz, 0);
     for (int i = 0; i < sz; ++i) {
       ops[i] = (i + 1) * prefix_count[i] - prefix_sum[i] + suffix_sum[i] - (i + 1) * suffix_count[i];
     }

     return ops;
   }
};
