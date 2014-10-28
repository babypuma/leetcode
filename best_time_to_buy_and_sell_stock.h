/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 *
 * Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * Problem:	Best Time to Buy and Sell Stock
 * Description: 
 * 	Say you have an array for which the ith element is the price of a given stock on day i.  
 *	If you were only permitted to complete at most one transaction 
 *	(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
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

		int maxProfit(vector<int> &xx) {
			int length = xx.size();
			int max_profit = 0;
			int min = 0;
			int max = 0;
			for (int i = 1; i < length; i++) {
				if (xx[i] < xx[min]) {
					min = i;
					max = i;
				}
				else if (xx[i] > xx[max]) {
					max = i;
				} 
				if (xx[max] - xx[min] > max_profit) { 
					max_profit = xx[max] - xx[min]; 
				}
			}

			return max_profit;
		}
};

