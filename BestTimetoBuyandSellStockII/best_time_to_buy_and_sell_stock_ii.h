/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/29
 * Update : 2020/10/17
 *
 * Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 * Problem:	Best Time to Buy and Sell Stock II
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int maxProfit(vector<int> &prices) {
     int length = prices.size();
     int sum = 0;
     int min = 0;
     int max = 0;
     for (int i = 1; i < length; i++) {
       if (prices[i] > prices[max]) {
         max = i;
       } else {
         sum += prices[max] - prices[min];	
         min = i;
         max = i;
       }
     }

     if (max > min) { 
       sum += prices[max] - prices[min];	
     }

     return sum;
   }
};
