/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/12
 *
 * Source : https://oj.leetcode.com/problems/search-in-rotated-sorted-array/
 * Problem:	Search in Rotated Sorted Array 
 * Description: 
 *	Suppose a sorted array is rotated at some pivot unknown to you beforehand.  
 *	(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *	You are given a target value to search. If found in the array return its index, otherwise return -1.
 *  You may assume no duplicate exists in the array.
 *
 */
class Solution {
	public:
	    int search(int A[], int n, int target) {
			return binarySearch(A, 0, n - 1, target);
		}

		int binarySearch(int A[], int left, int right, int target) {
			int middle;
			while (left <= right) {
				middle = (left + right) / 2;
				if (target == A[middle]) {
					return middle;
				}
				if (target < A[middle]) {
					if (target == A[right]) {
						return right;
					}
					if (A[middle] <= A[right]) {
						right = middle - 1;
					}
					else {
						if (target < A[right]) {
							left = middle + 1;
						}
						else {
							right = middle - 1;
						}
					}
				}
				else {
					if (target == A[left]) {
						return left;
					}
					if (A[middle] >= A[left]) {
						left = middle + 1;
					}
					else {
						if (target > A[left]) {
							right = middle - 1;
						}
						else {
							left = middle + 1;
						}
					}
				}
			}
			return -1;
		}
};
