/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/07/02
 *
 * Source : https://leetcode.com/problems/combination-sum-ii/
 * Problem:	Combination Sum II
 */
#include <vector>
using std::vector;

class Solution {
 public:
   vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
     solutions_.clear();
     target_ = target;
     std::sort(candidates.begin(), candidates.end());

     vector<int> solution;
     int sum = 0;
     backtrack(0, candidates, solution, sum);
     return solutions_;
   }

 private:
   void backtrack(int start, const vector<int>& candidates, vector<int>& solution, int& sum) {
     if (sum > target_) {
       return;
     }
     if (sum == target_) {
       if (!solutions_.empty() && solutions_.back() >= solution) {
         return;
       }
       solutions_.push_back(solution);
       return;
     }

     for (size_t i = start; i < candidates.size(); ++i) {
       solution.push_back(candidates[i]);
       sum += candidates[i];
       backtrack(i + 1, candidates, solution, sum);
       solution.pop_back();
       sum -= candidates[i];
     }
   }

 private:
   vector<vector<int> > solutions_;
   int target_;
};
