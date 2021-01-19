/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/20
 *
 * Source : https://leetcode-cn.com/problems/maximum-product-of-three-numbers/
 * Problem: Maximum Product of Three Numbers
 *               
 */
#include <vector>
#include <queue>
using std::vector;
using std::priority_queue;

class Solution {
 public:
   int maximumProduct(vector<int>& nums) {
     priority_queue<int, vector<int> > max_qu(nums.begin(), nums.end());
     priority_queue<int, vector<int>, std::greater<int> > min_qu(nums.begin(), nums.end());
     int m1 = max_qu.top();
     max_qu.pop();
     int m2 = max_qu.top();
     max_qu.pop();
     int m3 = max_qu.top();
     max_qu.pop();

     int m4 = min_qu.top();
     min_qu.pop();
     int m5 = min_qu.top();
     min_qu.pop();
     return std::max(m1 * m2 * m3, m1 * m4 * m5);
   }
};
