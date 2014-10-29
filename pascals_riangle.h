/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/30
 *
 * Source : https://oj.leetcode.com/problems/pascals-triangle/
 * Problem:	Pascal's Triangle
 * Description: 
 *	Given numRows, generate the first numRows of Pascal's triangle.
 *
 */
#include <vector>
using std::vector;

class Solution {
	public:
	    vector<vector<int> > generate(int numRows) { 
			vector<vector<int> > vec2d;
			for (int i = 0; i < numRows; i++) {
				vector<int> vec(i + 1, 1);
				vec2d.push_back(vec);
			}

			for (int i = 1; i < numRows; i++) {
				for (int j = 1; j < i; j++) {
					vec2d[i][j] = vec2d[i-1][j-1] + vec2d[i-1][j];
				}
			}
			
			return vec2d;
		}
};
