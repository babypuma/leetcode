/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/12/23
 *
 * Source :	https://oj.leetcode.com/problems/combinations/
 * Problem:	Combinations
 * Description: 
 *	Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *	For example,
 *	If n = 4 and k = 2, a solution is:
 * 	[
 *  	[2,4],
 *    	[3,4],
 *	   	[2,3],
 *	    [1,2],
 *		[1,3],
 *		[1,4],
 * 	]
 *
 */
#include <vector>
using std::vector;

class Solution {
	public:
	    vector<vector<int> > combine(int n, int k) { 
			vector<int> vec(k, 0);
			for (int i = 1; i <= n - k + 1; i++) {
				vec[0] = i;
				backtrack(vec, n, 1);
			}

			return vec2d;
		}

		void backtrack(vector<int> &vec, size_t n, size_t depth) {
			if (depth >= vec.size()) {
				vec2d.push_back(vec);
				return;
			}

			if (n - vec[depth - 1] < vec.size() - depth) {
				return;
			}
			
			for (size_t i = vec[depth - 1] + 1; i <= n; i++) {
				vec[depth] = i;
				backtrack(vec, n, depth + 1);
			}
		}

	private:
		vector<vector<int> > vec2d;
};
