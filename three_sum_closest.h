#include <algorithm>
#include <vector>
using std::vector;

class Solution {
	public:
	    int threeSumClosest(vector<int> &num, int target) {
			sort(num.begin(), num.end());
			int length = num.size();
			int sum;
			int index;
			int first;
			int gap = 0x7FFFFFFF;
			int closest;
			for (int i = 0; i < length - 2; i++) {
				if (i == 0) {
					first = num[0];
				}
				else {
					if (num[i] == first) {
						continue;
					}
					else {
						first = num[i];
					}
				}
				for (int j = i + 1; j < length - 1; j++) {
					sum = num[i] + num[j];
					index = binarySearch(num, j + 1, length - 1, target - sum);
					if (index < length && num[index] + sum - target < gap) {
						closest = num[index] + sum;
						gap = closest - target;
						if (gap == 0) {
							return target;
						}
					}
					if (index - 1 > j && target - sum - num[index-1] < gap) {
						closest = sum + num[index-1];
						gap = target - closest;
					} 
				}
			}

			return closest;
		}

		int binarySearch(vector<int> &vec, int left, int right, int val) {
			int mid;
			while (left <= right) {
				mid = (left + right)/2;
				if (vec[mid] == val) {
					return mid;
				}
				
				if (vec[mid] < val) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}

			return left;
		}
};
