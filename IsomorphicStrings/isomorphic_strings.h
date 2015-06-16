/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 *
 * Source : https://leetcode.com/problems/isomorphic-strings/
 * Problem:	Isomorphic Strings
 * Description: 
 *	Given two strings s and t, determine if they are isomorphic.
 * 	Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * 	All occurrences of a character must be replaced with another character 
 *	while preserving the order of characters. No two characters may map to 
 *	the same character but a character may map to itself.
 *
 * 	For example,
 * 		Given "egg", "add", return true.  
 *		Given "foo", "bar", return false.
 * 		Given "paper", "title", return true.
 *
 * 	Note: 
 *		You may assume both s and t have the same length.
 *
 */
#include <map>
#include <string>

using std::map;
using std::string;

class Solution {
	public: 
		bool isIsomorphic(string s, string t) {
			size_t size = s.size();
			if (size != t.size()) {
				return false;
			}

			int marks[256] = {0};
			map<char, char> table;
			for (size_t i = 0; i < size; i++) {
				if (table.find(s[i]) != table.end()) {
					if (table[s[i]] != t[i]) {
						return false;
					}
				} 
				else { 
					if (marks[t[i]] == 1) {
						return false;
					}
					table[s[i]] = t[i];
					marks[t[i]] = 1;
				}
			}

			return true;
		}
};
