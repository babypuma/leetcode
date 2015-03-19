/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/29
 *
 * Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 * Problem:	Best Time to Buy and Sell Stock II
 * Description: 
 *	Say you have an array for which the ith element is the price of a given stock on day i.
 * 	Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
 *	(ie, buy one and sell one share of the stock multiple times). 
 *	However, you may not engage in multiple transactions at the same time 
 * 	(ie, you must sell the stock before you buy again).
 *               
 */
#include <vector>
using std::vector;
using std::pair;

class Solution {
	public:
		struct Section {
			int min;
			int max;
			Section(int x = 0, int y = 0) : min(x), max(y) {}
		};

	    int maxProfit(vector<int> &prices) {
			int length = prices.size();
			int sum = 0;
			int min = 0;
			int max = 0;
			for (int i = 1; i < length; i++) {
				if (prices[i] > prices[max]) {
					max = i;
				}
				else {
					sum += prices[max] - prices[min];	
					min = i;
					max = i;
				}
			}

			if (max != min) { 
				sum += prices[max] - prices[min];	
			}

			return sum;
		}
};
