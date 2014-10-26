/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 *
 * Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
 * Problem:	Remove Duplicates from Sorted Array
 * Description: 
 *  Given a sorted array, remove the duplicates in place such that each element appear only once 
 *	and return the new length.
 *  Do not allocate extra space for another array, you must do this in place with constant memory.
 *  For example,
 *  Given input array A = [1,1,2],
 *  Your function should return length = 2, and A is now [1,2].
 *               
 */
class Solution {
	public:
	    int removeDuplicates(int A[], int n) { 
			int back = -1;
			int prev = A[0];
			for (int front = 1; front < n; front++) {
				if (A[front] != prev) {
					prev = A[front];
					if (back >= 0) {
						A[back++] = A[front];
					}
					continue;
				}
				if (back < 0) {
					back = front;
				}
			}

			return (back < 0) ? n : back;
		}
};
