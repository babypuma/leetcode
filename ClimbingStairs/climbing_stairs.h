/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/20
 *
 * Source : https://leetcode-cn.com/problems/climbing-stairs/
 * Problem:	Climbing Stairs
 *
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int climbStairs(int n) {
     if (n == 1) {
       return 1;
     } else if (n == 2) {
       return 2;
     }

     vector<int> vec(n + 1, 0);
     vec[1] = 1;
     vec[2] = 2;
     for (size_t i = 3; i < n + 1; ++i) {
       vec[i] = vec[i - 1] + vec[i - 2];
     }
     return vec[n];
   }
};
