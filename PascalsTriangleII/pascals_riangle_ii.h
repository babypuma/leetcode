/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/30
 *
 * Source : https://oj.leetcode.com/problems/pascals-triangle-ii/
 * Problem:	Pascal's Triangle II
 * Description: 
 *	Given an index k, return the kth row of the Pascal's triangle.
 *
 */
#include <vector>
using std::vector;

class Solution {
	public:
		vector<int> getRow(int rowIndex) {
			vector<int> vec(rowIndex+1, 1);
			for (int i = 2; i <= rowIndex; i++) {
				for (int j = i-1; j > 0; j--) {
					vec[j] += vec[j-1];
				}
			}
			
			return vec;
		}
};
