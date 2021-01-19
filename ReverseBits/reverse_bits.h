/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 * Update : 2021/01/19
 *
 * Source : https://leetcode-cn.com/problems/reverse-bits/
 * Problem: Reverse Bits
 *
 */
class Solution {
 public: 
   uint32_t reverseBits(uint32_t n) {
     uint32_t mark = 0x1;
     int bits = 31;
     uint32_t val = 0;
     int i;
     for (i = 0; i < 16; i++) {
       val |= (n & mark) << bits;
       mark <<= 1;
       bits -= 2;
     }

     bits = 1;
     for (i = 16; i < 32; i++) {
       val |= (n & mark) >> bits;
       mark <<= 1;
       bits += 2;
     }

     return val;
   }
};
