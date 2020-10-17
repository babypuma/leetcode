/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 * Update : 2020/10/17
 *
 * Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * Problem:	Best Time to Buy and Sell Stock
 *
 */
#include <vector>
using std::vector;

class Solution {
	public:
		int maxProfit(vector<int> &prices) {
			int length = prices.size();
			int max_profit = 0;
			int min = 0;
			int max = 0;
			for (int i = 1; i < length; i++) {
				if (prices[i] < prices[min]) {
					min = i;
					max = i;
				} else if (prices[i] > prices[max]) {
					max = i;
				} 

				if (prices[max] - prices[min] > max_profit) { 
					max_profit = prices[max] - prices[min]; 
				}
			}

			return max_profit;
		}
};

