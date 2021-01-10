/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/10
 *
 * Source : https://leetcode-cn.com/problems/decode-xored-array/
 * Problem: Decode XORed Array
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   vector<int> decode(vector<int>& encoded, int first) {
     int sz = encoded.size();
     vector<int> org(sz + 1);
     org[0] = first;
     for (int i = 1; i < sz + 1; ++i) {
       org[i] = org[i - 1] ^ encoded[i - 1];
     }

     return org;
   }
};
