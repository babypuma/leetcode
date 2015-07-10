/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/07/10
 *
 * Source : https://leetcode.com/problems/power-of-two/
 * Problem:	Power of Two
 * Description: 
 *	Given an integer, write a function to determine if it is a power of two.
 *
 */
class Solution {
	public:
	    bool isPowerOfTwo(int n) { 
			int count = 0;
			while (n > 0) {
				if (++count > 1) {
					return false;
				}
				n &= n - 1;
			}

			return count == 1;
		}
};
