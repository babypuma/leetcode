/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/14
 *
 * Source : https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 * Problem: Median of Two Sorted Arrays
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   bool lemonadeChange(vector<int>& bills) {
     int c5 = 0;
     int c10 = 0;
     for (auto& bill: bills) {
       if (bill == 5) {
         ++c5;
       } else if (bill == 10) {
         if (c5 == 0) {
           return false;
         }
         --c5;
         ++c10;
       } else if (bill == 20) {
         if ((c5 < 3 && c10 == 0) || c5 == 0) {
           return false;
         }
         if (c10 == 0) {
           c5 -= 3;
         } else {
           --c10;
           --c5;
         }
       }
     }

     return true;
   }
};
