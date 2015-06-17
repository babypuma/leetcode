/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/17
 *
 * Source : https://leetcode.com/problems/maximum-subarray/
 * Problem:	Maximum Subarray
 * Description: 
 *	Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 *
 * 	For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 *	the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 *
 */
#include <vector>

using std::vector;

class Solution {
	public: 
		int maxSubArray(vector<int>& nums) {
			size_t size = nums.size();
			int max = nums[0];
			int sum = 0;
			for (size_t i = 0; i < size; i++) {
				sum += nums[i];
				if (max < sum) {
					max = sum;
				}
				if (sum < 0) {
					sum = 0;
				}
			}
			return max;
		}
};
