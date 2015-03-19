/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 *
 * Source : https://oj.leetcode.com/problems/single-number/
 * Problem:	Single Number
 * Description: 
 *          Given an array of integers, every element appears twice except for one. Find that single one.
 * Note   : Your algorithm should have a linear runtime complexity. 
 * 			Could you implement it without using extra memory?
 *               
 */
class Solution {
	public:
	    int singleNumber(int A[], int n) {
			for (int i = 1; i < n; i++) {
				A[0] ^= A[i];
			}

			return A[0];
		}
};
