#include <string>
using std::string;

class Solution {
	public:
	    string convert(string s, int nRows) { 
			int length = s.size();
			int r = nRows;

			if (r == 1) {
				return s;
			}

			int i;
			int j;
			int k;
			int m = 0;
			char temp[length];
			for (j = 0; j < length; j += 2*(r-1)) {
				temp[m++] = s[j];
			}

			for (k = 1; k < r-1; k++) {
				for (i = k, j = 2*(r-1)-i; i < length && j < length; i += 2*(r-1), j += 2*(r-1)) {
					temp[m++] = s[i];
					temp[m++] = s[j];
				}

				if (i < length) {
					temp[m++] = s[i];
				}
			}

			for (j = r-1; j < length; j += 2*(r-1)) {
				temp[m++] = s[j];
			}

			return string(temp, length);
		}
};
