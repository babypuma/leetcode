/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/27
 *
 * Source : https://leetcode-cn.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/
 * Problem: Minimum Deletion Cost to Avoid Repeating Letters
 *               
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 public:
   int minCost(string s, vector<int>& cost) {
     int c = 0;
     int sum = 0;
     int m = 0;
     for (size_t i = 0; i < s.size(); ++i) {
       if (i == 0 || s[i] != s[i - 1]) {
         if (m != sum) {
           c += sum - m;
         }
         sum = cost[i];
         m = cost[i];
       } else {
         sum += cost[i];
         m = std::max(m, cost[i]);
       }
     }
     if (m != sum) {
       c += sum - m;
     }
     return c;
   }
};
