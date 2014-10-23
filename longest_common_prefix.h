#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
	public:
	    string longestCommonPrefix(vector<string> &strs) {
			int length = strs.size();
			if (length == 0) {
				return string("");
			}

			char prefix[strs[0].size() + 1];
			strcpy(prefix, strs[0].c_str());
			const char *word;
			for (int i = 0; i < length; i++) {
				word = strs[i].c_str();	
				int j;
				for (j = 0; word[j] != '\0' && prefix[j] != '\0'; j++) {
					if (word[j] != prefix[j]) {
						break;
					}
				} 
				prefix[j] = '\0';
			}

			return string(prefix);
		}
};
