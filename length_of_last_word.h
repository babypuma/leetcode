/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/12
 *
 * Source : https://oj.leetcode.com/problems/length-of-last-word/
 * Problem:	Length of Last Word
 * Description: 
 *	Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
 *	return the length of last word in the string.  
 *	If the last word does not exist, return 0.  
 * Note: 
 *	A word is defined as a character sequence consists of non-space characters only.  
 *	For example, 
 *	Given s = "Hello World",
 *	return 5.
 *
 */
class Solution {
	public:
	    int lengthOfLastWord(const char *s) {
			int length = 0;
			int curr_length = 0;
			for (const char *p = s; *p != '\0'; p++) {
				while (*(p + curr_length) != '\0' && *(p + curr_length) != ' ') {
					curr_length++;
				}
				if (*(p + curr_length) == '\0') {
					length = curr_length;
					break;
				}

				if (curr_length > 0) {
					p = p + curr_length;
					length = curr_length;
					curr_length = 0;
				}
			}

			return length;
		}
};
