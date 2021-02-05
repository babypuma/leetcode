/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/05
 *
 * Source : https://leetcode-cn.com/problems/get-equal-substrings-within-budget/
 * Problem: Get Equal Substrings Within Budget
 *               
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 public:
   int equalSubstring(string s, string t, int maxCost) {
     int sz = s.size();
     vector<int> costs(sz, 0);
     for (int i = 0; i < sz; ++i) {
       costs[i] = std::abs(s[i] - t[i]);
     }
     int ans = 0;
     int i = 0;
     int j = 0;
     int sum = 0;
     while (j < sz) {
       if (sum > maxCost) {
         sum -= costs[i];
         ++i;
       }
       sum += costs[j];
       if (sum <= maxCost) {
         ans = std::max(ans, j - i + 1);
       }
       ++j;
     }
     return ans;
   }
};
