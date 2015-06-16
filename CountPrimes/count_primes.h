/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 *
 * Source : https://leetcode.com/problems/house-robber/
 * Problem:	Count Primes
 * Description: 
 *	Count the number of prime numbers less than a non-negative number, n.
 *
 */
class Solution {
	public: 
		int countPrimes(int n) {
			if (n < 3) {
				return 0;
			}

			int *filter = (int *)calloc(n, sizeof(int));
			filter[2] = 1;
			for (int i = 3; i < n; i += 2) {
				filter[i] = 1;
			}

			for (int i = 3; i < n; i += 2) {
				for (int j = 3; j < n; j += 2) {
					if (i * j > n) {
						break;
					}
					filter[i * j] = 0;
				}
			}

			int count = 1;
			for (int i = 3; i < n; i += 2) {
				if (filter[i] == 1) {
					count++;
				}
			}

			free(filter);

			return count;
		}
};
