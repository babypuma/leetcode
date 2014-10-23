#include <vector>
#include <tr1/unordered_map>
using std::vector;
using std::tr1::unordered_map;

class Solution {
	public:
	    vector<vector<int> > threeSum(vector<int> &num) {
			vector<vector<int> > vv;
			unordered_map<int, int> vmap;
			unordered_map<int, int>::iterator it; 
			std::sort(num.begin(), num.end());
			int length = num.size();
			int sum;
			int index;
			int first;
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
					if (sum > 0) {
						break;
					} 
					if ((it = vmap.find(num[i])) != vmap.end() && it->second == num[j]) {
						continue;
					}
					if ((index = binarySearch(num, j + 1, length - 1, -sum)) != -1) { 
						vector<int> v;
						v.push_back(num[i]);
						v.push_back(num[j]);
						v.push_back(-sum);
						vv.push_back(v);
						vmap[num[i]] = num[j];
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
