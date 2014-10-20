#include <vector>
using std::vector;

class Solution {
	public:
	    double findMedianSortedArrays(int A[], int m, int B[], int n) { 
			vector<int> merged_array;
			int i = 0;
			int j = 0;
			while (i < m && j < n) {
				if (A[i] < B[j]) {
					merged_array.push_back(A[i++]);
				}
				else {
					merged_array.push_back(B[j++]);
				} 
			}

			if (i == m) {
				while (j < n) {
					merged_array.push_back(B[j++]);
				}
			}
			else if (j == n) {
				while (i < m) {
					merged_array.push_back(A[i++]);
				}
			}

			if ((m + n) % 2 == 0) {
				return ((double)merged_array[(m + n)/2 - 1] + merged_array[(m + n)/2])/2;
			}

			return (double)merged_array[(m + n)/2];
		}
};
