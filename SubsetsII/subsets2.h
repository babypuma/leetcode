/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/07/07
 *
 * Source : https://leetcode.com/problems/subsets-ii/
 * Problem:	Subsets II
 */
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
   vector<vector<int> > subsetsWithDup(vector<int>& nums) {
     solution_.clear();
     std::sort(nums.begin(), nums.end());
     vector<int> solution;
     backtrack(0, nums, solution);
     return solution_;
   }

 private:
   void backtrack(int start, const vector<int>& candidates, vector<int>& solution) {
     if (!solution_.empty() && solution_.back() >= solution) {
       return;
     }
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
