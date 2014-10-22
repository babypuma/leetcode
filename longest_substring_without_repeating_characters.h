#include <string>
using std::string;

class Solution {
	public:
	    int lengthOfLongestSubstring(string s) {
			int bitmap[256];
			for (int j = 0; j < 256; j++) {
				bitmap[j] = 0;
			}

			size_t max = 0;
			size_t begin = 0;
			size_t i = 0;
			size_t length = s.size();
			while (i < length) {
				if (bitmap[s[i]] > 0) {
					if (i - begin > max) {
						max = i - begin;
					}
					begin = bitmap[s[i]];
					for (int j = 0; j < 256; j++) {
						bitmap[j] = 0;
					}
					i = begin;
				}
				else {
					bitmap[s[i]] = i + 1;
					i++;
				}
			}

			if (length - begin > max) {
				max = length - begin;
			}

			return max;
		}
};
