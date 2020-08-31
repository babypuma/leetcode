/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/08/31
 *
 * Source : https://leetcode.com/problems/split-array-into-fibonacci-sequence/
 * Problem:	Split Array into Fibonacci Sequence
 *
 */
#include <vector>
#include <string>
#include <stdexcept>

using std::vector;
using std::string;

class Solution {
 public:
   vector<int> splitIntoFibonacci(string S) {
     vector<int> index;
     vector<int> candidates;
     vector<int> solution;
     index.push_back(-1);
     backtrack(S, 0, index, candidates, solution);
     return solution;
   }

 private:
   void backtrack(const string& s, int start, vector<int>& index, vector<int>& candidates, vector<int>& solution) {
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
       int num = 0;
       try {
         num = stoi(s.substr(index.back() + 1, i - index.back()));
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

   bool isFibonacci(vector<int>& candidates) {
     size_t back = candidates.size() - 1;
     return candidates[back] - candidates[back - 1] == candidates[back - 2];
   }
};
