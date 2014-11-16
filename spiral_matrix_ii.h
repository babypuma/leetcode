/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/16
 *
 * Source : https://oj.leetcode.com/problems/spiral-matrix-ii/
 * Problem:	Spiral Matrix II
 * Description:
 *	Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 *	For example,
 *	Given n = 3,
 *	You should return the following matrix:
 *	[
 *	 [ 1, 2, 3 ],
 *   [ 8, 9, 4 ],
 *   [ 7, 6, 5 ]
 *	]
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

		vector<vector<int> > generateMatrix(int n) {
			count = 1;
			vector<vector<int> > matrix;
			if (n <= 0) {
				return matrix;
			}
			else if (n == 1) {
				vector<int> vec(1, 1);
				matrix.push_back(vec);
			}
			else {
				for (size_t i = 0; i < n; i++) {
					vector<int> vec(n, 0);
					matrix.push_back(vec);
				}
			}

			size_t max_length = n * n;
			distance = n - 1;
			Index start(0, 0);
			Index end(0, distance);
			while (count <= max_length) {
				left2right(matrix, start, end);

				start.reset(end);
				end.reset(start.r + distance, start.c);
				top2bottom(matrix, start, end);

				start.reset(end);
				end.reset(start.r, start.c - distance);
				right2left(matrix, start, end);

				start.reset(end);
				end.reset(start.r - distance, start.c);
				bottom2top(matrix, start, end);

				distance -= 2;
				start.reset(end.r + 1, end.c + 1);
				end.reset(start.r, start.c + distance);
			}
			return matrix;
		}

	private:
		void left2right(vector<vector<int> > &matrix, Index start, Index end) {
			if (start.c > end.c || (start.c == end.c && distance > 0)) {
				return;
			}

			int i = start.c;
			do {
				matrix[start.r][i] = count++;
				i++;
			} while (i < end.c);
		}

		void top2bottom(vector<vector<int> > &matrix, Index start, Index end) {
			if (start.c != end.c || start.r >= end.r) {
				return;
			}
			for (int i = start.r; i < end.r; i++) {
				matrix[i][start.c] = count++;
			}
		}

		void right2left(vector<vector<int> > &matrix, Index start, Index end) {
			if (start.r != end.r || start.c <= end.c) {
				return;
			}
			for (int i = start.c; i > end.c; i--) {
				matrix[start.r][i] = count++;
			}
		}

		void bottom2top(vector<vector<int> > &matrix, Index start, Index end) {
			if (start.c != end.c || start.r <= end.r) {
				return;
			}
			for (int i = start.r; i > end.r; i--) {
				matrix[i][start.c] = count++;
			}
		}
	
		vector<int> vec; 
		int distance;
		size_t count;
};
