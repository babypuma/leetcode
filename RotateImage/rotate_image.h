/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/09
 *
 * Source : https://oj.leetcode.com/problems/rotate-image/
 * Problem:	Rotate Image
 * Description: 
 *	You are given an n x n 2D matrix representing an image.  
 *	Rotate the image by 90 degrees (clockwise).  
 *	Follow up: 
 *	Could you do this in-place?
 *
 */
#include <vector>
using std::vector;

class Solution {
	public:
	    void rotate(vector<vector<int> > &matrix) {
			size_t n = matrix.size();
			int temp;
			for (size_t i = 0; i < n/2; i++) { 
				for (size_t j = i; j < (n - 1) - i; j++) {
					temp = matrix[i][j];
					matrix[i][j] = matrix[(n - 1) - j][i];
					matrix[(n - 1) - j][i] = matrix[(n - 1) - i][(n - 1) - j];
					matrix[(n - 1) - i][(n - 1) - j] = matrix[j][(n - 1) - i];
					matrix[j][(n - 1) - i] = temp;
				}
			}
		}
};
