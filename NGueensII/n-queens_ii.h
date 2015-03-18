/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/12/21
 *
 * Source : https://oj.leetcode.com/problems/n-queens-ii/
 * Problem:	N-Queens II
 * Description: 
 *	Follow up for N-Queens problem.  
 *	Now, instead outputting board configurations, return the total number of distinct solutions.
 *
 */
#include <vector>

using std::vector;

class Solution {
	public:
		Solution() : count(0) {}
		int totalNQueens(int n) {
			vector<int> v(n, 0);
			for (int i = 0; i < n; i++) {
				v[0] = i;
				backtrack(v, n, 1);
			}

			return count;
		}

		void backtrack(vector<int> &vec, size_t n, size_t depth) {
			if (depth >= n) {
				count++;
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
		int count;
};
