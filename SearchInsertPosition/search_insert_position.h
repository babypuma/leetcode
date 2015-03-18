/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/02
 *
 * Source : https://oj.leetcode.com/problems/search-insert-position/
 * Problem:	Search Insert Position
 * Description: 
 *	Given a sorted array and a target value, return the index if the target is found. 
 *	If not, return the index where it would be if it were inserted in order.  
 *	You may assume no duplicates in the array.
 *
 *	Here are few examples.
 *	[1,3,5,6], 5 → 2
 *	[1,3,5,6], 2 → 1
 *	[1,3,5,6], 7 → 4
 *	[1,3,5,6], 0 → 0
 *
 */
class Solution {
	public:
	    int searchInsert(int A[], int n, int target) { 
			return binarySearch(A, n, target);
		}

		int binarySearch(int A[], int n, int target) {
			int left = 0;
			int right = n - 1;
			int middle;
			while (left <= right) {
				middle = (left + right) / 2;
				if (A[middle] == target) {
					return middle;
				}

				if (A[middle] > target) {
					right = middle - 1;
				}
				else {
					left = middle + 1;
				}
			}

			return left;
		}
};
