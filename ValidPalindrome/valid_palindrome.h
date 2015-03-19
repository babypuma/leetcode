/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/30
 *
 * Source : https://oj.leetcode.com/problems/valid-palindrome/
 * Problem:	Valid Palindrome 
 * Description: 
 *	Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.  
 *	For example, 
 *	"A man, a plan, a canal: Panama" is a palindrome.  
 *	"race a car" is not a palindrome.
 *
 */
#include <ctype.h>
#include <string>
using std::string;

class Solution {
	public:
	    bool isPalindrome(string s) { 
			int length = s.size();
			int i = 0;
			int j = length - 1;
			while (i < j) {
				while (i < length && !isalpha(s[i]) && !isdigit(s[i])) {
					i++;
				}
				while (j >= 0 && !isalpha(s[j]) && !isdigit(s[j])) {
					j--;
				}

				if (i > j) {
					break;
				}

				if (isalpha(s[i]) && isalpha(s[j])) {
					int n = s[i] - s[j];
					if (n == 0 || n == GAP || n == -GAP) {
						i++;
						j--;
					}
					else {
						return false;
					}
				}
				else if (isdigit(s[i]) && isdigit(s[j])) {
					if (s[i] == s[j]) {
						i++;
						j--;
					}
					else {
						return false;
					}
				}
				else {
					return false;
				}
			}

			return true;
		}

		static const int GAP = 'A' - 'a';
};
