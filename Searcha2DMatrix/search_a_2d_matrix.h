/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/16
 *
 * Source : https://oj.leetcode.com/problems/search-a-2d-matrix/
 * Problem:	Search a 2D Matrix
 * Description:
 *	Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *	Integers in each row are sorted from left to right.
 *	The first integer of each row is greater than the last integer of the previous row.
 *	For example,
 *	Consider the following matrix:
 *  [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *	 [23, 30, 34, 50]
 *  ]
 *	Given target = 3, return true.
 *
 */
#include <vector>
using std::vector;

class Solution {
	public:
	    bool searchMatrix(vector<vector<int> > &matrix, int target) {
			int number_of_row = matrix.size();
			if (number_of_row == 0) {
				return false;
			}
			number_of_column = matrix[0].size();
			return binarySearch(matrix, target, 0, number_of_row * number_of_column - 1);
		}

		bool binarySearch(vector<vector<int> > &matrix, int target, int left, int right) {
			int middle;
			int row;
			int column;
			int value;
			while (left <= right) {
				middle = (left + right)/2;
				row = middle / number_of_column;
				column = middle % number_of_column;
				value = matrix[row][column];
				if (target == value) {
					return true;
				}
				else if (target < value) {
					right = middle - 1;
				}
				else {
					left = middle + 1;
				}
			}

			return false;
		}
	
	private:
		int number_of_column;
};
