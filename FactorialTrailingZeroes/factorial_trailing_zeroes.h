/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/15
 *
 * Source : https://leetcode.com/problems/factorial-trailing-zeroes/
 * Problem:	Factorial Trailing Zeroes 
 * Description: 
 *	Given an integer n, return the number of trailing zeroes in n!.  
 *	Note: Your solution should be in logarithmic time complexity.
 *
 */
class Solution {
	public:
		int trailingZeroes(int n) {
			int num = 0;
			int factor = 5;
			while (factor <= n) {
				num += n / factor;
				if (factor > INT32_MAX / 5) {
					break;
				} 
				factor *= 5;
			}

			return num;
		}
};
