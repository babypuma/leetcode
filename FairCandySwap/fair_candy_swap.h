/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/01
 *
 * Source : https://leetcode-cn.com/problems/fair-candy-swap/
 * Problem: Fair Candy Swap
 *               
 */
#include <unordered_set>
#include <vector>
using std::unordered_set;
using std::vector;

class Solution {
 public:
   vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
     int s1 = 0;
     for (auto& c : A) {
       s1 += c;
     }
     int s2 = 0;
     unordered_set<int> coll;
     for (auto& c : B) {
       s2 += c;
       coll.insert(c);
     }
     int gap = s1 - s2;

     vector<int> swap(2);
     for (int j = 0; j < A.size(); ++j) {
       if (coll.count(A[j] - gap/2) > 0) {
         swap[0] = A[j];
         swap[1] = A[j] - gap/2;
         break;
       }
     }
     return swap;
   }
};
