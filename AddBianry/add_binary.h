/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/09
 *
 * Source : https://oj.leetcode.com/problems/add-binary/
 * Problem:	Add Binary
 * Description: 
 *	Given two binary strings, return their sum (also a binary string).  
 *	For example,
 *	a = "11"
 *	b = "1"
 *	Return "100".
 *
 */
#include <string>
using std::string;

class Solution {
	public:
		Solution() {
			int2char[0] = '0';
			int2char[1] = '1';
		}
	    string addBinary(string a, string b) {
			int length1 = a.size();
			int length2 = b.size();
			char c[(length1 > length2 ? length1 : length2) + 2];
			char f = '0';
			int index = 0;
			while (length1 > 0 && length2 > 0) {
				c[index++] = sum(a[length1 - 1], b[length2 - 1], f);
				f = flag(a[length1 - 1], b[length2 - 1], f);
				length1--;	
				length2--;	
			}
			while (length1 > 0) {
				c[index++] = sum(a[length1 - 1], '0', f);
				f = flag(a[length1 - 1], '0', f);
				length1--;
			}
			while (length2 > 0) {
				c[index++] = sum('0', b[length2 - 1], f);
				f = flag('0', b[length2 - 1], f);
				length2--;	
			}
			if (f == '1') {
				c[index++] = '1';
			}
			c[index] = '\0';

			for (int i = 0; i < index/2; i++) {
				char temp = c[i];
				c[i] = c[(index - 1)- i];
				c[(index - 1)- i] = temp;
			}

			return string(c);
		}

		char sum(char x, char y, char f) {
			int a = x - '0';
			int b = y - '0';
			int flag = f - '0';
			return int2char[(a + b + flag) % 2];
		}

		char flag(char x, char y, char f) {
			int a = x - '0';
			int b = y - '0';
			int flag = f - '0';
			return int2char[(a + b + flag) / 2];
		}

	private:
		char int2char[2];
}; 

