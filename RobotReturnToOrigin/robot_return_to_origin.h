/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/19
 *
 * Source : https://leetcode-cn.com/problems/robot-return-to-origin/
 * Problem: Robot Return to Origin
 *               
 */
#include <string>
using std::string;

class Solution {
 public:
   bool judgeCircle(string moves) {
     int h = 0;
     int v = 0;
     for (auto& m : moves) {
       switch (m) {
         case 'U':
           ++v;
           break;
         case 'D':
           --v;
           break;
         case 'L':
           ++h;
           break;
         case 'R':
           --h;
           break;
       }
     }
     return h == 0 && v == 0;
   }
};
