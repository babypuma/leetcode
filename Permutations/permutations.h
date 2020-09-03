/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/03
 *
 * Source : https://leetcode.com/problems/permutations/
 * Problem:	Permutations
 */
#include <vector>
#include <unordered_set>
using std::vector;
using std::unordered_set;

class Solution {
 public:
   vector<vector<int> > permute(vector<int>& nums) {
     std::sort(nums.begin(), nums.end());

     vector<int> solution;
     unordered_set<int> index;
     vector<vector<int> > solutions;
     backtrack(nums, solution, index, solutions);
     return solutions;
   }

 private:
   void backtrack(const vector<int>& candidates, vector<int>& solution, unordered_set<int>& index, vector<vector<int> >& solutions) {
     if (solution.size() == candidates.size()) {
       solutions.push_back(solution);
       return;
     }
     for (size_t i = 0; i < candidates.size(); ++i) {
       if (index.find(i) != index.end()) {
         continue;
       }
       solution.push_back(candidates[i]);
       index.insert(i);
       backtrack(candidates, solution, index, solutions);
       index.erase(i);
       solution.pop_back();
     }
   }
};
