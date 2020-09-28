/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/26
 *
 * Source : https://leetcode-cn.com/problems/maximum-sum-circular-subarray/
 * Problem:	Maximum Sum Circular Subarray
 *
 */
#include <vector>
#include <algorithm>
using std::vector;
using std::max;

class Solution {
 public:
   int maxSubarraySumCircular(vector<int>& A) {
     if (A.size() == 1) {
       return A[0];
     }

     int s1 = kanade(A, 0, A.size() - 1, 1);
     int s2 = kanade(A, 0, A.size() - 2, -1);
     int s3 = kanade(A, 1, A.size() - 1, -1);
     int sum = 0;
     for (size_t i = 0; i < A.size(); ++i) {
       sum += A[i];
     }
     return max(s1, max(sum + s2, sum + s3));
   }

 private:
   int kanade(vector<int>& A, int i, int j, int sign) {
     int sum = A[i] * sign;
     int m = A[i] * sign;
     for (size_t k = i + 1; k <= j; ++k) {
       sum = max(sum + A[k] * sign, A[k] * sign);
       m = max(m, sum);
     }
     return m;
   }
};
