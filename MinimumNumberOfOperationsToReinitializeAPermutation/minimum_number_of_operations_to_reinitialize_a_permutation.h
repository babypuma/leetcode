/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/28
 *
 * Source : https://leetcode-cn.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/
 * Problem: Minimum Number of Operations to Reinitialize a Permutation
 *               
 */
#include <vector>
#include <unordered_set>
using std::vector;
using std::unordered_set;

class Solution {
 public:
   int reinitializePermutation(int n) {
     vector<int> seq(n, -1);
     int ans = 0;
     for (int i = 0; i < n; ++i) {
       int j = i;
       int step = 0;
       do {
         if (j % 2 == 0) {
           j >>= 1;
         } else {
           j >>= 1;
           j += (n >> 1);
         }
         if (seq[j] > 0) {
           seq[i] = seq[j];
           break;
         }
         ++step;
       } while (j != i);
       if (seq[i] < 0) {
         seq[i] = step;
       }
       ans = std::max(ans, seq[i]);
     }
     return ans;
   }
};
