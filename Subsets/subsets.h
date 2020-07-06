/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/07/07
 *
 * Source : https://leetcode.com/problems/subsets/
 * Problem:	Subsets
 */
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
   vector<vector<int> > subsets(vector<int>& nums) {
     solution_.clear();
     vector<int> solution;
     backtrack(0, nums, solution);
     return solution_;
   }

 private:
   void backtrack(int start, const vector<int>& candidates, vector<int>& solution) {
     solution_.push_back(solution);
     if (candidates.size() == solution.size()) {
       return;
     }

     for (size_t i = start; i < candidates.size(); ++i) {
       solution.push_back(candidates[i]);
       backtrack(i + 1, candidates, solution);
       solution.pop_back();
     }
   }

 private:
   vector<vector<int> > solution_;
};
