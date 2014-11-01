/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/02
 *
 * Source : https://oj.leetcode.com/problems/unique-binary-search-trees/
 * Problem:	Unique Binary Search Trees
 * Description: 
 *	Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 *
 */
class Solution {
	public:
	    int numTrees(int n) {
			int num[n+1];
			memset(num, 0, sizeof(num));
			num[0] = 1;
			num[1] = 1;
			
			return number(num, n);
		}
		
		int number(int a[], int n) {
			if (a[n] > 0) {
				return a[n];
			}

			int sum = 0;
			for (int i = 0; i < n; i++) {
				sum += number(a, i) * number(a, (n-1)-i);
			}

			return sum;
		}
};
