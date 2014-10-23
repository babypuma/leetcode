#include <vector>
using std::vector;

class Solution {
	public:
	    bool isPalindrome(int x) {
			if (x < 0) {
				return false;
			}
			vector<int>	vec;
			while (x > 0) {
				vec.push_back(x % 10);
				x /= 10;
			}
			size_t length = vec.size();
			for (size_t i = 0; i < length/2; i++) {
				if (vec[i] != vec[length - i - 1]) {
					return false;
				}
			}

			return true;
		}
};
