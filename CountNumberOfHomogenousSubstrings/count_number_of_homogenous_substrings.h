/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/14
 *
 * Source : https://leetcode-cn.com/problems/count-number-of-homogenous-substrings/
 * Problem: Count Number of Homogenous Substrings
 *               
 */
#include <string>
using std::string;

class Solution {
 public:
   int countHomogenous(string s) {
     int num = 0;
     int len = 1;
     for (size_t i = 1; i < s.size(); ++i) {
       if (s[i] == s[i - 1]) {
         ++len;
       } else {
         int tmp = countHomogenous(len);
         num += (NUM - num <= tmp) ? (tmp - NUM) : tmp;
         len = 1;
       }
     }

     int tmp = countHomogenous(len);
     return num += (NUM - num <= tmp) ? (tmp - NUM) : tmp;
   }

 private:
   // 计算n * (n + 1) / 2
   int countHomogenous(int n) {
     if (n <= THRESHOLD) {
       return (n & 1) ? ((n + 1) >> 1) * n : (n >> 1) * (n + 1);
     }

     int num = (THRESHOLD >> 1) * (THRESHOLD + 1);
     for (int i = THRESHOLD + 1; i <= n; ++i) {
       num += i;
       num %= NUM;
     }
     return num;
   }

   static const int THRESHOLD = 40000;
   static const int NUM = 1000000007;
};
