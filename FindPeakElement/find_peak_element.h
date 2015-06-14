#include <vector>
using std::vector;

class Solution {
	public:
	    int findPeakElement(vector<int>& nums) {
			size_t size = nums.size();
			if (size == 0) {
				return -1;
			}
			if (size == 1) {
				return 0;
			}
			for (size_t i = 0; i < size - 1; i++) {
				if (nums[i] > nums[i + 1]) {
					return i;
				}
			}

			return size - 1;
		}
};
