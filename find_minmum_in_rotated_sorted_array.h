/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/02
 *
 * Source : https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 * Problem:	Find Minimum in Rotated Sorted Array 
 * Description: 
 *	Suppose a sorted array is rotated at some pivot unknown to you beforehand.  
 *	(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *	Find the minimum element.
 * 	You may assume no duplicate exists in the array.
 *
 */
#include <vector>
using std::vector;

class Solution {
	public:
	    int findMin(vector<int> &num) {
			return num[binarySearch(num)];
		}
		
		int binarySearch(vector<int> &num) {
			int left = 0;
			int right = num.size() - 1;
			int middle;
			while (num[left] > num[right]) {
				if (left + 1 == right) {
					return right;
				}
				middle = (left + right) / 2;
				if (num[middle] >= num[left]) {
					left = middle;
				}
				else {
					right = middle;
				}
			}

			return left;
		}
};
