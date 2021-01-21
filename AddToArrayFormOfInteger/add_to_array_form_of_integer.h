/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/22
 *
 * Source : https://leetcode-cn.com/problems/add-to-array-form-of-integer/
 * Problem: Add to Array-Form of Integer
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   vector<int> addToArrayForm(vector<int>& A, int K) {
     if (K == 0) {
       return A;
     }

     vector<int> B;
     while (K > 0) {
       B.push_back(K % 10);
       K /= 10;
     }

     int carry = 0;
     std::reverse(A.begin(), A.end());
     for (size_t i = 0; i < A.size() && i < B.size(); ++i) {
       int sum = A[i] + B[i] + carry;
       carry = sum / 10;
       B[i] = sum % 10;
     }
     if (A.size() == B.size()) {
       if (carry > 0) {
         B.push_back(carry);
       }
     } else if (A.size() < B.size()) {
       for (size_t i = A.size(); i < B.size(); ++i) {
         B[i] += carry;
         carry = B[i] / 10;
         B[i] %= 10;
         if (carry == 0) {
           break;
         }
       }
       if (carry > 0) {
         B.push_back(carry);
       }
     } else {
       for (size_t i = B.size(); i < A.size(); ++i) {
         B.push_back(A[i] + carry);
         carry = B.back() / 10;
         B.back() %= 10;
       }
       if (carry > 0) {
         B.push_back(carry);
       }
     }
     std::reverse(B.begin(), B.end());
     return B;
   }
};
