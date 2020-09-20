/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/20
 *
 * Source : https://leetcode-cn.com/problems/minimum-swaps-to-make-sequences-increasing/
 * Problem:	Minimum Swaps To Make Sequences Increasing
 *
 */
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
 public:
   int minSwap(vector<int>& A, vector<int>& B) {
     vector<int> swapVec(A.size(), 1);
     vector<int> noSwapVec(A.size(), 0);
     for (size_t i = 1; i < A.size(); ++i) {
       if (A[i - 1] < B[i] && B[i - 1] < A[i] && A[i - 1] < A[i] && B[i - 1] < B[i]) {
         noSwapVec[i] = std::min(noSwapVec[i - 1], swapVec[i - 1]);
         swapVec[i] = std::min(noSwapVec[i - 1], swapVec[i - 1]) + 1;
       } else if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
         noSwapVec[i] = swapVec[i - 1];
         swapVec[i] = noSwapVec[i - 1] + 1;
       } else if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
         noSwapVec[i] = noSwapVec[i - 1];
         swapVec[i] = swapVec[i - 1] + 1;
       }
     }

     return std::min(noSwapVec[A.size() - 1], swapVec[A.size() - 1]);
   }
};
