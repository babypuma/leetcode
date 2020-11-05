/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/11/05
 *
 * Source : https://leetcode-cn.com/problems/subarray-sums-divisible-by-k/
 * Problem:	Subarray Sums Divisible by K
 *
 */
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
 public:
   int subarraysDivByK(vector<int>& A, int K) {
     int sum = 0;
     int count = 0;
     unordered_map<int, int> prefix_sum;
     int aux = 10000 - (10000 % K);
     for (int i = 0; i < A.size(); ++i) {
       sum = (sum + A[i]) % K;
       if (sum < 0) {
         sum = (sum + aux) % K;
       }
       if (sum == 0) {
         ++count;
       }
       if (prefix_sum.count(sum) > 0) {
         count += prefix_sum[sum];
       }
       ++prefix_sum[sum];
     }

     return count;
   }
};
