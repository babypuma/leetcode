/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/16
 *
 * Source : https://oj.leetcode.com/problems/set-matrix-zeroes/
 * Problem:	Set Matrix Zeroes
 * Description:
 *	Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 *	click to show follow up.
 *	Follow up:
 *	Did you use extra space?
 *	A straight forward solution using O(mn) space is probably a bad idea.
 *	A simple improvement uses O(m + n) space, but still not the best solution.
 *	Could you devise a constant space solution?
 *
 */
#include <vector>
#include <set>
using std::vector;
using std::set;

class Solution {
	public:
	    void setZeroes(vector<vector<int> > &matrix) {
			set<int> rows;
			set<int> columns;
			int m = matrix.size();
			if (m == 0) {
				return;
			}
			int n = matrix[0].size();
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (matrix[i][j] == 0) {
						rows.insert(i);
						columns.insert(j);
					}
				}
			}

			for (set<int>::iterator it = rows.begin(); it != rows.end(); it++) {
				for (int j = 0; j < n; j++) {
					matrix[*it][j] = 0;
				}
			}

			for (set<int>::iterator it = columns.begin(); it != columns.end(); it++) {
				for (int i = 0; i < m; i++) {
					matrix[i][*it] = 0;
				}
			}
		}
};
