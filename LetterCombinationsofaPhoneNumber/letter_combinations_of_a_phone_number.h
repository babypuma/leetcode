/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/06/30
 *
 * Source : https://leetcode.com/problems/letter-combinations-of-a-phone-number
 * Problem: Letter Combinations of a Phone Number
 */
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
 public:
   Solution() {
     digit2letter[2] = "abc";
     digit2letter[3] = "def";
     digit2letter[4] = "ghi";
     digit2letter[5] = "jkl";
     digit2letter[6] = "mno";
     digit2letter[7] = "pqrs";
     digit2letter[8] = "tuv";
     digit2letter[9] = "wxyz";
   }

   vector<string> letterCombinations(string digits) {
     solution_.clear();
     if (digits.empty()) {
       return solution_;
     }
     string solution;
     backtrack(0, digits, solution);
     return solution_;
   }

   void backtrack(int start, const string& source, string& solution) {
     if (solution.size() == source.size()) {
       solution_.push_back(solution);
       return;
     }
     for (int i = start; i < source.size(); ++i) {
       int digit = static_cast<int>(source[i] - '0');
       int len = strlen(digit2letter[digit]);
       for (int j = 0; j < len; ++j) {
         solution.push_back(digit2letter[digit][j]);
         backtrack(i + 1, source, solution);
         solution.pop_back();
       }
     }
   }

 private:
   char *digit2letter[10];
   vector<string> solution_;
};
