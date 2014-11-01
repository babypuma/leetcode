/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/01
 *
 * Source : https://oj.leetcode.com/problems/plus-one/
 * Problem:	Plus One
 * Description: 
 *	Given a non-negative number represented as an array of digits, plus one to the number.  
 *	The digits are stored such that the most significant digit is at the head of the list.
 *
 */
#include <vector>
using std::vector;

class Solution {
	public:
	    vector<int> plusOne(vector<int> &digits) { 
			int length = digits.size();
			if (length == 0) {
				digits.push_back(1);
				return digits;
			}
			
			int carry = 0;
			int sum = 0;
			for (int i = length - 1; i >= 0; i--) { 
				if (i < length - 1) {
					sum = digits[i] + carry;
				}
				else {
					sum = digits[i] + 1;
				}

				carry = sum / 10;
				digits[i] = sum % 10;
				if (carry == 0) {
					return digits;
				}
			}

			digits.push_back(digits[length-1]);
			for (int i = length - 1; i > 0; i--) {
				digits[i] = digits[i-1];
			}
			digits[0] = 1;

			return digits;
		}
};
