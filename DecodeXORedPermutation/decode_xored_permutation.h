/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/25
 *
 * Source : https://leetcode-cn.com/problems/decode-xored-permutation/
 * Problem: Decode XORed Permutation
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   vector<int> decode(vector<int>& encoded) {
     int sz = encoded.size();
     vector<int> perm(sz + 1);
     int x1 = 0;
     for (int i = 1; i < sz; i += 2) {
       x1 ^= encoded[i];
     }
     int x2 = 0;
     for (int i = 1; i <= sz + 1; ++i) {
       x2 ^= i;
     }
     perm[0] = x1 ^ x2;
     for (int i = 1; i < sz + 1; ++i) {
       perm[i] = perm[i - 1] ^ encoded[i - 1];
     }
     return perm;
   }
};
