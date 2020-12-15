/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/16
 *
 * Source : https://leetcode-cn.com/problems/read-n-characters-given-read4/
 * Problem: Read N Characters Given Read4
 *               
 */
#include <cstring>

int read4(char *buf4) {
}

class Solution {
 public:
   int read(char *buf, int n) {
     int m = 0;
     int cnt = 0;
     char buf4[5];
     while ((m = read4(buf4)) != 0) {
       if (cnt + m < n) {
         strncpy(buf + cnt, buf4, m);
         cnt += m;
       } else {
         strncpy(buf + cnt, buf4, n - cnt);
         cnt = n;
         break;
       }
     }
     return cnt;
   }
};
