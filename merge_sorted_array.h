/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/01
 *
 * Source : https://oj.leetcode.com/problems/merge-sorted-array/
 * Problem:	Merge Sorted Array
 * Description: 
 *	Given two sorted integer arrays A and B, merge B into A as one sorted array.  
 * Note:
 *	You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements 
 *	from B. The number of elements initialized in A and B are m and n respectively.
 *
 */
class Solution {
	public:
	    void merge(int A[], int m, int B[], int n) {
			int index = m + n - 1;
			m--;
			n--;
			while (m >= 0 && n >= 0) {
				if (A[m] > B[n]) {
					A[index] = A[m];
					m--;
				}
				else {
					A[index] = B[n];
					n--;
				} 
				index--;
			}

			while (n >= 0) {
				A[index--] = B[n--];
			}
		}
};
