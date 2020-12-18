/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/17
 *
 * Source : https://leetcode-cn.com/problems/height-checker/
 * Problem: Height Checker
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int heightChecker(vector<int>& heights) {
     vector<int> counter(MAX_HEIGHT + 1, 0);
     for (auto& h : heights) {
       ++counter[h];
     }
     for (size_t i = 1; i < MAX_HEIGHT + 1; ++i) {
       counter[i] += counter[i - 1];
     }
     int cnt = 0;
     for (int i = 0; i < heights.size(); ++i) {
       if (i >= counter[heights[i] - 1] && i < counter[heights[i]]) {
       } else {
         ++cnt;
       }
     }
     return cnt;
   }

 private:
   static const int MAX_HEIGHT = 100;
};
