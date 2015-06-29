/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/29
 *
 * Source : https://leetcode.com/problems/summary-ranges/
 * Problem:	Summary Ranges
 * Description: 
 *	Given a sorted integer array without duplicates, return the summary of its ranges.
 * 	For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 *
 */
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
	public: 
		vector<string> summaryRanges(vector<int>& nums) {
			vector<string> vec;
			if (nums.empty()) {
				return vec;
			}

			string str = itos(nums[0]);
			size_t size = nums.size();
			for (size_t i = 1; i < size; i++) {
				if (nums[i] == nums[i - 1] + 1) {
					if (i == size - 1 || nums[i] + 1 != nums[i + 1]) {
						str += "->";
						str += itos(nums[i]);
						vec.push_back(str);
						str.clear();
					}
				}
				else if (nums[i] != nums[i - 1] + 1) {
					if (!str.empty()) {
						vec.push_back(str);
						str.clear();
					} 
					str = itos(nums[i]);
				}
			}

			if (!str.empty()) {
				vec.push_back(str);
			}

			return vec;
		}
	
		string itos(int num) {
			string s;
			if (num < 0) {
				if (num == INT32_MIN) {
					return "-2147483648";
				}
				s = "-";
				return s + itos(-num);
			}
			else if (num == 0) {
				return "0";
			}

			while (num > 0) {
				s += (num % 10) + '0';
				num /= 10;
			}
			reverse(s);
			return s;
		}

		void reverse(string& s) {
			size_t size = s.size();
			for (size_t i = 0; i < size/2; i++) {
				char ch = s[i];
				s[i] = s[size - 1 - i];
				s[size - 1 - i] = ch;
			}
		}
};
