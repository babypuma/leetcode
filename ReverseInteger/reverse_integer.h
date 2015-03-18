#include <vector>
using std::vector;

class Solution {
	public:
	    int reverse(int x) {
			if (x == 0) {
				return 0;
			}

			int sign = x > 0 ? 1 : -1;
			if (x < 0) {
				x = -x;
			}

			vector<int> bits;
			while (x > 0) {
				bits.push_back(x%10);
				x /= 10;
			}

			int y = 0;
			for (vector<int>::iterator it = bits.begin(); it != bits.end(); it++) {
				y *= 10;
				y += *it;
			}

			return y * sign;
		}
};
