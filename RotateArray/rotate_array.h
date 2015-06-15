/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 *
 * Source : https://leetcode.com/problems/rotate-array/
 * Problem:	Rotate Array
 * Description: 
 *	Rotate an array of n elements to the right by k steps.
 *  For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 *
 * 	Note:
 * 		Try to come up as many solutions as you can, there are at least 3 different ways 
 *		to solve this problem.
 *
 */
#include <vector>

using std::vector;

class Solution {
	public:
		void rotate(vector<int>& nums, int k) {
			size_t size = nums.size();
			if ((k %= size) == 0) {
				return;
			}
			reverse(nums, 0, size);
			reverse(nums, 0, k);
			reverse(nums, k, size - k);
		}

		void reverse(vector<int>& vec, size_t pos, size_t len) {
			size_t tail = pos + len - 1;
			int tmp;
			for (size_t i = 0; i < len / 2; i++) {
				tmp = vec[pos + i];
				vec[pos + i] = vec[tail - i];
				vec[tail - i] = tmp;
			}
		}
};
