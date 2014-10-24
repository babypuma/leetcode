#include <algorithm>
#include <vector>
using std::vector;

class Solution {
	public:
	    vector<vector<int> > fourSum(vector<int> &num, int target) {
			vector<vector<int> > vv;
			sort(num.begin(), num.end());
			int length = num.size();
			int pair_sum;
			int tuple_sum;
			int index;
			int first;
			int second;
			int third;
			for (int i = 0; i < length - 3; i++) {
				if (i == 0) {
					first = num[i];
				}
				else {
					if (num[i] == first) {
						continue;
					}
					else {
						first = num[i];
					}
				}
				if (num[i] >= 0 && num[i] > target) {
					break;
				}

				for (int j = i + 1; j < length - 2; j++) {
					if (j == i + 1) {
						second = num[j];
					}
					else {
						if (num[j] == second) {
							continue;
						}
						else {
							second = num[j];
						}
					}
					pair_sum = num[i] + num[j];
					if (num[j] >= 0 && pair_sum > target) {
						break;
					}

					for (int k = j + 1; k < length - 1; k++) {
						if (k == j + 1) {
							third = num[k];
						}
						else {
							if (num[k] == third) {
								continue;
							}
							else {
								third = num[k];
							}
						}

						tuple_sum = pair_sum + num[k];
						if (num[k] >= 0 && tuple_sum > target) {
							break;
						} 
						if ((index = binarySearch(num, k + 1, length - 1, target - tuple_sum)) != -1) { 
							vector<int> v;
							v.push_back(num[i]);
							v.push_back(num[j]);
							v.push_back(num[k]);
							v.push_back(target - tuple_sum);
							vv.push_back(v);
						}
					}
				}
			}
		
			return vv; 
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

			return -1;
		}
};
