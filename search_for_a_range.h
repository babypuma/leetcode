/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/19
 *
 * Source : https://oj.leetcode.com/problems/search-for-a-range/
 * Problem:	Search for a Range
 * Description:
 *	Given a sorted array of integers, find the starting and ending position of a given target value.
 *	Your algorithm's runtime complexity must be in the order of O(log n).
 *	If the target is not found in the array, return [-1, -1].
 *	For example,
 *	Given [5, 7, 7, 8, 8, 10] and target value 8,
 *	return [3, 4].
 *
 */
#include <vector>
using std::vector;

class Solution {
	public:
		Solution() : min(-1), max(-1) {}

	    vector<int> searchRange(int A[], int n, int target) {
			binarySearchMin(A, 0, n - 1, target);
			binarySearchMax(A, 0, n - 1, target);
			vector<int> vec;
			vec.push_back(min);
			vec.push_back(max);

			return vec;
		}

		void binarySearchMin(int A[], int left, int right, int target) {
			if (left > right) {
				return;
			}
			int middle = (left + right)/2;
			if (A[middle] == target) {
				min = middle;
				binarySearchMin(A, left, middle - 1, target);
				return;
			}

			if (A[middle] < target) {
				binarySearchMin(A, middle + 1, right, target);
			}
			else {
				binarySearchMin(A, left, middle - 1, target);
			}
		}

		void binarySearchMax(int A[], int left, int right, int target) {
			if (left > right) {
				return;
			}
			int middle = (left + right)/2;
			if (A[middle] == target) {
				max = middle;
				binarySearchMax(A, middle + 1, right, target);
				return;
			}

			if (A[middle] < target) {
				binarySearchMax(A, middle + 1, right, target);
			}
			else {
				binarySearchMax(A, left, middle - 1, target);
			}
		}

	private:
		int min;
		int max;
};
