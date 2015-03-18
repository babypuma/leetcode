/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/06
 *
 * Source : https://oj.leetcode.com/problems/permutations/
 * Problem:	Permutations
 * Description: 
 *	Given a collection of numbers, return all possible permutations.  
 *	For example,
 *	[1,2,3] have the following permutations:
 *	[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 *
 */
#include <vector>
using std::vector;

class Solution {
	public:
		vector<vector<int> > permute(vector<int> &num) {
			vector<vector<int> > vec;
			vec.push_back(num);

			size_t length = factorial(num.size());
			while (vec.size() < length) {
				nextPermutation(num);
				vec.push_back(num);
			}

			return vec;
		}

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

		size_t factorial(size_t n) {
			size_t sum = 1;
			for (size_t i = 2; i < n + 1; i++) {
				sum *= i;
			}

			return sum;
		}
};
