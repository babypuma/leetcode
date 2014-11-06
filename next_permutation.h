/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/06
 *
 * Source : https://oj.leetcode.com/problems/next-permutation/
 * Problem:	Next Permutation
 * Description: 
 *	Implement next permutation, which rearranges numbers into the lexicographically 
 *	next greater permutation of numbers.  
 *	If such arrangement is not possible, it must rearrange it as the lowest possible order 
 *	(ie, sorted in ascending order).  
 *	The replacement must be in-place, do not allocate extra memory.  
 *	Here are some examples. Inputs are in the left-hand column and 
 *	its corresponding outputs are in the right-hand column.
 * 	1,2,3 → 1,3,2
 *	3,2,1 → 1,2,3
 *	1,1,5 → 1,5,1
 *
 */
#include <vector>
using std::vector;

class Solution {
	public:
	    void nextPermutation(vector<int> &num) {
			int length = num.size();
			int i = length - 2;
			for (; i >= 0; i--) {
				if (num[i] < num[i + 1]) {
					break;
				}
			}
			if (i < 0) {
				reverse(num, 0, length - 1);
				return;
			}

			int index = length - 1;
			for (; index >= 0; index--) {
				if (num[index] > num[i]) {
					break;
				}
			}
			swap(num, i, index);
			reverse(num, i + 1, length - 1);
		}

		void reverse(vector<int> &vec, int begin, int end) {
			int length = vec.size();
			if (end > length - 1 || end - begin < 1) {
				return;
			}
			int mid = (end - begin)/2; 
			int temp;
			for (int i = 0; i <= mid; i++) {
				temp = vec[begin + i];
				vec[begin + i] = vec[end - i];
				vec[end - i] = temp;
			}
		}

		void swap(vector<int> &vec, size_t i, size_t j) {
			size_t length = vec.size();
			if (i == j || i >= length || j >= length) {
				return;
			}
			int temp = vec[i];
			vec[i] = vec[j];
			vec[j] = temp;
		}
};
