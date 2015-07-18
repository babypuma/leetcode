/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 *
 * Source : https://leetcode.com/problems/product-of-array-except-self/
 * Problem:	Product of Array Except Self
 * Description: 
 *	Given an array of n integers where n > 1, nums, return an array output such that 
 *	output[i] is equal to the product of all the elements of nums except nums[i].
 *
 *	Solve it without division and in O(n).
 *
 * 	For example, given [1,2,3,4], return [24,12,8,6].
 *
 * Follow up:
 *	Could you solve it with constant space complexity? (Note: The output array does not count 
 *	as extra space for the purpose of space complexity analysis.)
 *
 */
#include <vector>
using std::vector;

class Solution {
	public:
	    vector<int> productExceptSelf(vector<int>& nums) {
			int n = nums.size();
			vector<int> vec(n, 1);
			for (int i = 1; i < n; i++) {
				vec[i] = nums[i - 1] * vec[i - 1];
			}

			int mul = nums[n - 1];
			for (int i = n - 2; i > 0; i--) {
				vec[i] *= mul;
				mul *= nums[i];
			}
			vec[0] *= mul;
			
			return vec;
		}
};
