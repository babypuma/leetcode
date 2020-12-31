/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/01
 *
 * Source : https://leetcode-cn.com/problems/can-place-flowers/
 * Problem: Can Place Flowers
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   bool canPlaceFlowers(vector<int>& flowerbed, int n) {
     int count = 0;
     int sz = flowerbed.size();
     for (int i = 0; i < sz;) {
       if ((i == 0 || flowerbed[i - 1] == 0) && flowerbed[i] == 0 && (i == sz - 1 || flowerbed[i + 1] == 0)) {
         if (++count >= n) {
           return true;
         }
         i += 2;
       } else {
         ++i;
       }
     }

     return count >= n;
   }
};
