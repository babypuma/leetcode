/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/08/05
 *
 * Source : https://leetcode.com/problems/maximum-swap/
 * Problem:	Maximum Swap
 *
 */
#include <vector>
#include <queue>

using std::vector;
using std::priority_queue;

class Solution {
 public:
   int maximumSwap(int num) {
     vector<int32_t> vec;
     while (num > 0) {
       vec.push_back(num % 10);
       num /= 10;
     }

     getMaxNum(vec);

     int n = 0;
     size_t len = vec.size();
     for (int i = len - 1; i >= 0; i--) {
       n *= 10;
       n += vec[i];
     }

     return n;
   }

 private:
   void getMaxNum(vector<int32_t>& vec) {
     priority_queue<int32_t> que;
     size_t len = vec.size();
     for (size_t i = 0; i < len; ++i) {
       que.push((vec[i] << 16) + i);
     }

     size_t idx = len - 1;
     while (!que.empty()) {
       int32_t num = que.top();
       que.pop();

       int32_t real_num = (num >> 16);
       size_t index = num & 0xFFFF;
       if (real_num != vec[idx]) {
         if (!que.empty() && (que.top() >> 16) == real_num) {
           continue;
         }
         int32_t tmp = vec[idx];
         vec[idx] = vec[index];
         vec[index] = tmp;
         break;
       }
       idx--;
     }
   }
};
