/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/16
 *
 * Source : https://oj.leetcode.com/problems/spiral-matrix/
 * Problem:	Spiral Matrix
 * Description:
 *	Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 *	For example,
 *	Given the following matrix:
 *	[
 *	 [ 1, 2, 3 ],
 *   [ 4, 5, 6 ],
 *   [ 7, 8, 9 ]
 *	]
 *	You should return [1,2,3,6,9,8,7,4,5].
 *
 */
#include <vector>
using std::vector;

class Solution {
	public:
		struct Index {
			int r;
			int c;
			Index(int row, int col) : r(row), c(col) {}
			void reset(const Index &p) {
				r = p.r;
				c = p.c;
			}
			void reset(int row, int col) {
				r = row;
				c = col;
			}
		};

	    vector<int> spiralOrder(vector<vector<int> > &matrix) {
			size_t m = matrix.size();
			if (m == 0) return vec;
			if (m == 1) return matrix[0];

			size_t n = matrix[0].size();
			if (n == 1) {
				for (size_t i = 0; i < m; i++) {
					vec.push_back(matrix[i][0]);
				}
				return vec;
			}

			size_t max_length = m * n;
			horizontal_distance = n - 1;
			vertical_distance = m - 1;
			Index start(0, 0);
			Index end(0, horizontal_distance);
			while (vec.size() < max_length) {
				left2right(matrix, start, end);

				start.reset(end);
				end.reset(start.r + vertical_distance, start.c);
				top2bottom(matrix, start, end);

				start.reset(end);
				end.reset(start.r, start.c - horizontal_distance);
				right2left(matrix, start, end);

				start.reset(end);
				end.reset(start.r - vertical_distance, start.c);
				bottom2top(matrix, start, end);

				horizontal_distance -= 2;
				vertical_distance -= 2;
				start.reset(end.r + 1, end.c + 1);
				end.reset(start.r, start.c + horizontal_distance);
			}

			return vec;
		}

	private:
		void left2right(vector<vector<int> > &matrix, Index start, Index end) {
			if (start.c > end.c || (start.c == end.c && vertical_distance > 0)) {
				return;
			}

			int i = start.c;
			do {
				vec.push_back(matrix[start.r][i]);
				i++;
			} while (i < end.c);
		}

		void top2bottom(vector<vector<int> > &matrix, Index start, Index end) {
			if (start.c != end.c || start.r >= end.r) {
				return;
			}
			for (int i = start.r; i < end.r; i++) {
				vec.push_back(matrix[i][start.c]);
			}
		}

		void right2left(vector<vector<int> > &matrix, Index start, Index end) {
			if (start.r != end.r || start.c <= end.c) {
				return;
			}
			for (int i = start.c; i > end.c; i--) {
				vec.push_back(matrix[start.r][i]);
			}
		}

		void bottom2top(vector<vector<int> > &matrix, Index start, Index end) {
			if (start.c != end.c || start.r <= end.r) {
				return;
			}
			for (int i = start.r; i > end.r; i--) {
				vec.push_back(matrix[i][start.c]);
			}
		}
	
		vector<int> vec; 
		int horizontal_distance;
		int vertical_distance;
};
