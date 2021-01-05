/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/06/30
 * Update : 2021/01/05
 *
 * Source : https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
 * Problem: Letter Combinations of a Phone Number
 *
 */
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
 public:
   vector<string> letterCombinations(string digits) {
     string letter_table[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
     vector<string> keyboard(letter_table, letter_table + sizeof(letter_table)/sizeof(letter_table[0]));

     vector<string> solution;
     if (digits.empty()) {
       return solution;
     }

     string comb;
     backtrack(keyboard, 0, digits, comb, solution);
     return solution;
   }

 private:
   void backtrack(vector<string>& keyboard, int start, const string& digits, string& comb, vector<string>& solution) {
     if (comb.size() == digits.size()) {
       solution.push_back(comb);
       return;
     }

     int idx = digits[start] - '0';
     for (size_t i = 0; i < keyboard[idx].size(); ++i) {
       comb.push_back(keyboard[idx][i]);
       backtrack(keyboard, start + 1, digits, comb, solution);
       comb.pop_back();
     }
   }
};

