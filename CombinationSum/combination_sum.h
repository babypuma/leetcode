#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
      vector<int> vec;
      vector<vector<int> > result;
      int sum = 0;
      backtracking(candidates, target, 0, sum, vec, result);
      return result;
    }

private:
    void backtracking(const vector<int>& candidates,
                      const int target,
                      int level,
                      int& sum,
                      vector<int>& vec,
                      vector<vector<int> >& result) {
      if (sum > target) {
        return;
      }
      if (sum == target) {
        result.push_back(vec);
        return;
      }
      for (size_t i = level; i < candidates.size(); ++i) {
        sum += candidates[i];
        vec.push_back(candidates[i]);
        backtracking(candidates, target, i, sum, vec, result);
        vec.pop_back();
        sum -= candidates[i];
      }
    }
};
