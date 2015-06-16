/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 *
 * Source : https://leetcode.com/problems/happy-number/
 * Problem:	Happy Number
 * Description: 
 *	Write an algorithm to determine if a number is "happy".
 *
 * 	A happy number is a number defined by the following process: Starting with 
 *	any positive integer, replace the number by the sum of the squares of its digits, 
 *	and repeat the process until the number equals 1 (where it will stay), or it loops 
 *	endlessly in a cycle which does not include 1. Those numbers for which this process 
 *	ends in 1 are happy numbers.
 *
 * 	Example: 19 is a happy number
 * 	1^2 + 9^2 = 82
 * 	8^2 + 2^2 = 68
 *	6^2 + 8^2 = 100
 *  1&2 + 0^2 + 0^2 = 1
 *
 */
#include <set>
using std::set;

class Solution {
	public: 
		bool isHappy(int n) {
			set<int> nums;
			do {
				nums.insert(n);
				n = squareOfDigits(n);
			} while (n != 1 && nums.find(n) == nums.end());

			return n == 1;
		}

		int squareOfDigits(int n) {
			int sum = 0;
			int digit;
			while (n > 0) {
				digit = n % 10;
				sum += digit * digit;
				n /= 10;
			}

			return sum;
		}
};
