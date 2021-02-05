/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/06
 *
 * Source : https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards/
 * Problem: Maximum Points You Can Obtain from Cards
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int maxScore(vector<int>& cardPoints, int k) {
     int sz = cardPoints.size();
     int sum = 0;
     for (int i = 0; i < k; ++i) {
       sum += cardPoints[i];
     }
     int ans = sum;
     for (int i = k - 1; i >= 0; --i) {
       sum -= cardPoints[i];
       sum += cardPoints[sz - (k - i)];
       ans = std::max(ans, sum);
     }
     return ans;
   }
};
