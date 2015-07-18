/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/07/18
 *
 * Source : https://leetcode.com/problems/sort-colors/
 * Problem:	Sort Colors
 * Description: 
 *	Given an array with n objects colored red, white or blue, sort them so that 
 *	objects of the same color are adjacent, with the colors in the order red, white and blue.
 *
 * 	Here, we will use the integers 0, 1, and 2 to represent the color red, white, 
 *	and blue respectively.
 *
 * Note:
 *	You are not suppose to use the library's sort function for this problem.
 *
 */
#include <algorithm>
#include <vector>
using std::vector;

class Solution {
	public:
	    void sortColors(vector<int>& nums) {
			random_shuffle(nums.begin(), nums.end());
			sort(nums, 0, nums.size() - 1);		        
		}

	private:
		void sort(vector<int>& vec, int lo, int hi) {
			if (lo >= hi) {
				return;
			}
			
			int lt = lo;
			int i = lo + 1;
			int gt = hi;
			int val = vec[lo];
			while (i <= gt) {
				if (vec[i] < val) 		swap(vec, lt++, i++);
				else if (vec[i] > val)	swap(vec, i, gt--);
				else 					i++;
			}
			sort(vec, lo, lt - 1);
			sort(vec, gt + 1, hi);
		}

		void swap(vector<int>& vec, int a, int b) {
			int tmp = vec[a];
			vec[a] = vec[b];
			vec[b] = tmp;
		}
};
