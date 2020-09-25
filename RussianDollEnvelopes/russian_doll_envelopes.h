/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/25
 *
 * Source : https://leetcode-cn.com/problems/russian-doll-envelopes/
 * Problem:	Russian Doll Envelopes
 *
 */
#include <vector>
#include <algorithm>
using std::vector;

bool MyComparator(const vector<int>& v1, const vector<int>& v2) {
  if (v1.empty()) {
    return true;
  } else if (v2.empty()) {
    return false;
  }
  return v1[0] < v2[0];
}

class Solution {
 public:
   int maxEnvelopes(vector<vector<int> >& envelopes) {
     std::sort(envelopes.begin(), envelopes.end(), MyComparator);
     vector<int> dp(envelopes.size(), 1);
     for (size_t i = 1; i < dp.size(); ++i) {
       for (size_t j = 0; j < i; ++j) {
         if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
           dp[i] = std::max(dp[i], dp[j] + 1);
         }
       }
     }
     int max = 0;
     for (size_t i = 0; i < dp.size(); ++i) {
       if (max < dp[i]) {
         max = dp[i];
       }
     }
     return max;
   }
};
