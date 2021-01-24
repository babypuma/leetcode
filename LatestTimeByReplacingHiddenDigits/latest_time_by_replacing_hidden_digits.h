/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/24
 *
 * Source : https://leetcode-cn.com/problems/latest-time-by-replacing-hidden-digits/
 * Problem: Latest Time by Replacing Hidden Digits
 *               
 */
#include <string>
using std::string;

class Solution {
 public:
   string maximumTime(string time) {
     if (time[0] == '?') {
       if (time[1] >= '4' && time[1] <= '9') {
         time[0] = '1';
       } else {
         time[0] = '2';
       }
     }
     if (time[1] == '?') {
       if (time[0] == '2') {
         time[1] = '3';
       } else {
         time[1] = '9';
       }
     }
     if (time[3] == '?') {
       time[3] = '5';
     }
     if (time[4] == '?') {
       time[4] = '9';
     }
     return time;
   }
};
