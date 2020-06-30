/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/06/30
 *
 * Source : https://leetcode.com/problems/letter-case-permutation/
 * Problem:	Letter Case Permutation
 */
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
   vector<string> letterCasePermutation(string S) {
     solution_.clear();
     string solution;
     backtrack(0, S, solution);
     return solution_;
   }

 private:
   void backtrack(int start, const string& source, string solution) {
     if (solution.size() == source.size()) {
       solution_.push_back(solution);
       return;
     }

     for (int i = start; i < source.size(); ++i) {
       solution.push_back(source[i]);
       backtrack(i + 1, source, solution);
       solution.pop_back();

       if (isalpha(source[i])) {
         solution.push_back(isupper(source[i]) ? tolower(source[i]) : toupper(source[i]));
         backtrack(i + 1, source, solution);
         solution.pop_back();
       }
     }
   }

 private:
   vector<string> solution_;
};
