/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/15
 *
 * Source : https://leetcode.com/problems/majority-element/
 * Problem:	Majority Element
 * Description: 
 * 	Given an array of size n, find the majority element. The majority element is the element 
 *	that appears more than ⌊ n/2 ⌋ times.  
 *	You may assume that the array is non-empty and the majority element always exist in the array.
 *
 */
#include <vector>

using std::vector;

class Solution {
	public:
		int majorityElement(vector<int>& nums) {
			size_t size = nums.size();
			int candidate = nums[0];
			int count = 1;
			for (size_t i = 1; i < size; i++) {
				if (candidate == nums[i]) {
					count++;
				}
				else {
					count--;
				}
				if (count == 0) {
					candidate = nums[i];
					count = 1;
				}
			}

			return candidate;
		}
};
