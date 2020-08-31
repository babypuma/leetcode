/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/08/31
 *
 * Source : https://leetcode.com/problems/additive-number/
 * Problem:	Additive Number
 *
 */
#include <vector>
#include <string>
#include <stdexcept>

using std::vector;
using std::string;

class Solution {
 public:
   bool isAdditiveNumber(string num) {
     vector<int64_t> index;
     vector<int64_t> candidates;
     vector<int64_t> solution;
     index.push_back(-1);
     backtrack(num, 0, index, candidates, solution);
     return !solution.empty();
   }

 private:
   void backtrack(const string& s, int start, vector<int64_t>& index, vector<int64_t>& candidates, vector<int64_t>& solution) {
     if (!solution.empty()) {
       return;
     }
     if (candidates.size() >= 3 && !isFibonacci(candidates)) {
       return;
     }
     if (index.back() == s.size() - 1) {
       if (candidates.size() >= 3 && isFibonacci(candidates)) {
         solution = candidates;
       }
       return;
     }

     for (size_t i = start; i < s.size(); ++i) {
       if (s[index.back() + 1] == '0' && i != index.back() + 1) {
         return;
       }
       int64_t num = 0;
       try {
         num = stoll(s.substr(index.back() + 1, i - index.back()));
       } catch (const std::out_of_range& oor) {
         return;
       }
       candidates.push_back(num);
       index.push_back(i);
       backtrack(s, i + 1, index, candidates, solution);
       index.pop_back();
       candidates.pop_back();
     }
   }

   bool isFibonacci(vector<int64_t>& candidates) {
     size_t back = candidates.size() - 1;
     return candidates[back] - candidates[back - 1] == candidates[back - 2];
   }
};
