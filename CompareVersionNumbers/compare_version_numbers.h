/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/15
 *
 * Source : https://oj.leetcode.com/problems/compare-version-numbers/
 * Problem:	Compare Version Numbers
 * Description: 
 *	Compare two version numbers version1 and version2.
 *	If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 *
 *  You may assume that the version strings are non-empty and contain only digits and the . character.
 *  The . character does not represent a decimal point and is used to separate number sequences.
 *  For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level 
 *	revision of the second first-level revision.
 * 
 *  Here is an example of version numbers ordering:
 *  0.1 < 1.1 < 1.2 < 13.37
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
	public:
		int compareVersion(string version1, string version2) {
			vector<int> v1 = split(version1);
			vector<int> v2 = split(version2);
			return compare(v1, v2);
		}

		vector<int> split(string version) {
			vector<int> vec;
			size_t begin = 0;
			size_t end;
			string sub;
			while ((end = version.find('.', begin)) != string::npos) {
				sub = version.substr(begin, end - begin);
				if (sub.empty()) {
					vec.push_back(0);
				}
				else {
					vec.push_back(strtoul(sub.c_str(), NULL, 10));
				}
				begin = end + 1;
			}

			if (begin != string::npos) { 
				sub = version.substr(begin);
				vec.push_back(strtoul(sub.c_str(), NULL, 10));
			}
			else {
				vec.push_back(0);
			}
			return vec;
		}

		int compare(vector<int>& v1, vector<int>& v2) {
			size_t s1 = v1.size();
			size_t s2 = v2.size();
			size_t i;
			for (i = 0; i < s1 && i < s2; i++) {
				if (v1[i] < v2[i]) {
					return -1;
				}
				else if (v1[i] > v2[i]) {
					return 1;
				}
			}

			if (s1 == s2) {
				return 0;
			}
			if (s1 < s2) {
				for (; i < s2; i++) {
					if (v2[i] != 0) {
						return -1;
					}
				}
			}
			else {
				for (; i < s1; i++) {
					if (v1[i] != 0) {
						return 1;
					}
				}
			}

			return 0;
		}
};
