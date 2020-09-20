/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/21
 *
 * Source : https://leetcode-cn.com/problems/domino-and-tromino-tiling/
 * Problem:	Domino and Tromino Tiling
 *
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int numTilings(int N) {
     if (N == 1) {
       return 1;
     } else if (N == 2) {
       return 2;
     }

     const int m = 1000000007;
     vector<uint64_t> vec1(N + 1, 0);
     vec1[1] = 1;
     vec1[2] = 2;
     vector<uint64_t> vec2(N + 1, 0);
     vec2[1] = 0;
     vec2[2] = 1;
     for (size_t i = 3; i < N + 1; ++i) {
       vec2[i] = (vec1[i - 2] + vec2[i - 1]) % m;
       vec1[i] = (vec2[i] + vec1[i - 1] + vec2[i - 1]) % m;
     }

     return vec1[N];
   }
};
