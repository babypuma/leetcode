/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 *
 * Source : https://oj.leetcode.com/problems/divide-two-integers/
 * Problem:	Divide Two Integers 
 * Description: 
 * 			Divide two integers without using multiplication, division and mod operator. 
 *               
 */
class Solution {
	public:
	    int divide(int dividend, int divisor) {
			int sign = 1;
			if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
				sign = -1;
			}

			int n = 0; 
			if (dividend == MY_INT32_MIN) {
				if (divisor == MY_INT32_MIN) {
					return 1;
				}
				if (divisor < 0) {
					divisor = -divisor;
				}
				dividend = MY_INT32_MAX - (divisor - 1);
				n = 1;
			}

			if (divisor == MY_INT32_MIN) {
				if (dividend == MY_INT32_MAX) {
					return 0;
				}
				divisor = MY_INT32_MAX;
			}

			if (dividend < 0) {
				dividend = -dividend;
			}
			if (divisor < 0) {
				divisor = -divisor;
			}

			while (dividend >= divisor) {
				int m = 1;
				int multiple_divisor = divisor;
				while (dividend >= multiple_divisor) {
					dividend -= multiple_divisor;
					n += m;
					if ((multiple_divisor << 1) < 0) {
						break;
					}
					multiple_divisor <<= 1;	
					m <<= 1;
				}
			}
		
			return (sign == -1) ? (~n + 1) : n;
		} 
		
		static const int MY_INT32_MAX = 0x7FFFFFFF;
		static const int MY_INT32_MIN = 0x80000000;
};
