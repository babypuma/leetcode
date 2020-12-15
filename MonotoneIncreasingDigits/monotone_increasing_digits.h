/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/15
 *
 * Source : https://leetcode-cn.com/problems/monotone-increasing-digits/
 * Problem: Monotone Increasing Digits
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int monotoneIncreasingDigits(int N) {
     vector<int> bits;
     while (N > 0) {
       bits.push_back(N % 10);
       N /= 10;
     }
     std::reverse(bits.begin(), bits.end());
     for (size_t i = 0; i < bits.size() - 1; ++i) {
       if (bits[i] <= bits[i + 1]) {
         continue;
       }
       int j = i;
       while (j > 0 && bits[j] == bits[j - 1]) {
         --j;
       }
       --bits[j];
       for (size_t k = j + 1; k < bits.size(); ++k) {
         bits[k] = 9;
       }
       break;
     }

     int num = 0;
     for (size_t i = 0; i < bits.size(); ++i) {
       num *= 10;
       num += bits[i];
     }
     return num;
   }
};
