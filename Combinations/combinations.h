/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/12/23
 * Update : 2021/01/08
 *
 * Source :	https://leetcode-cn.com/problems/combinations/
 * Problem:	Combinations
 *
 */
#include <vector>
using std::vector;

class Solution {
 public:
   vector<vector<int> > combine(int n, int k) { 
     vector<vector<int> > solution;
     vector<int> candidate;
     backtrack(n, k, 1, candidate, solution);
     return solution;
   }

 private:
   void backtrack(int n, int k, int start, vector<int>& candidate, vector<vector<int> >& solution) {
     if (candidate.size() == k) {
       solution.push_back(candidate);
       return;
     }
     for (int i = start; i <= n; ++i) {
       candidate.push_back(i);
       backtrack(n, k, i + 1, candidate, solution);
       candidate.pop_back();
     }
   }
};
