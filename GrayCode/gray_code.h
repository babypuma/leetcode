/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/07
 *
 * Source : https://oj.leetcode.com/problems/gray-code/
 * Problem:	Gray Code
 * Description: 
 * 	The gray code is a binary numeral system where two successive values differ in only one bit.  
 *	Given a non-negative integer n representing the total number of bits in the code, 
 *	print the sequence of gray code. A gray code sequence must begin with 0.  
 *	For example, given n = 2, return [0,1,3,2]. Its gray code sequence is: 
 *	00 - 0
 *	01 - 1
 *	11 - 3
 *	10 - 2 
 * Note:
 *	For a given n, a gray code sequence is not uniquely defined.
 * 	For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.  
 *	For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
 *
 */
#include <vector>
#include <math.h>
using std::vector;

class Solution {
	public:
	    vector<int> grayCode(int n) {
			size_t num = (size_t)pow(2, n);
			vector<int> vec(num, 0);

			size_t length = 2;
			for (size_t i = 1; i < num; i++) {
				if (i >= length) {
					length <<= 1;
				}
				vec[i] = vec[(length - 1) - i] | (length >> 1);
			}

			return vec;
		}
};
