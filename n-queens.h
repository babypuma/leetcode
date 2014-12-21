/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/12/21
 *
 * Source : https://oj.leetcode.com/problems/n-queens/
 * Problem:	N-Queens
 * Description: 
 *	The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that 
 *	no two queens attack each other.  
 *	Given an integer n, return all distinct solutions to the n-queens puzzle.  
 *	Each solution contains a distinct board configuration of the n-queens' placement, 
 *	where 'Q' and '.' both indicate a queen and an empty space respectively.  
 *	For example,
 *	There exist two distinct solutions to the 4-queens puzzle: 
 *	[ 
 *		[".Q..",  // Solution 1 
 *		 "...Q",
 *		 "Q...",
 *		 "..Q."], 
 *		["..Q.",  // Solution 2
 *		 "Q...",
 *		 "...Q",
 *		 ".Q.."]
 *	]
 *
 */
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
	public:
	    vector<vector<string> > solveNQueens(int n) { 
			vector<int> v(n, 0);
			for (int i = 0; i < n; i++) {
				v[0] = i;
				backtrack(v, n, 1);
			}

			return vec2d;
		}

		void backtrack(vector<int> &vec, size_t n, size_t depth) {
			if (depth >= n) {
				vector<string> solution;
				for (size_t i = 0; i < n; i++) {
					string str(n, '.');
					str[vec[i]] = 'Q';
					solution.push_back(str);
				}
				vec2d.push_back(solution);
				return;
			}
			
			for (size_t i = 0; i < n; i++) {
				if (!attack(vec, depth, i)) {
					vec[depth] = i;
					backtrack(vec, n, depth + 1);
				}
			}
		}
		
		bool attack(vector<int> &vec, size_t depth, int curr) {
			int x;
			int y;
			for (size_t i = 0; i < depth; i++) {
				x = depth - i;
				y = curr - vec[i];
				if (x == 0 || y == 0 || x == y || x + y == 0) {
					return true;
				}
			}

			return false;
		}

	private:
		vector<vector<string> > vec2d;
};
