/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/03/18
 * Update : 2021/01/05
 *
 * Source : https://leetcode-cn.com/problems/generate-parentheses/
 * Problem: Generate Parentheses
 *               
 */
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
 public:
   vector<string> generateParenthesis(int n) {
     vector<string> solution;
     string str;
     backtrack(0, 0, n, str, solution);
     return solution;
   }

 private:
   void backtrack(int left_count, int right_count, int n, string& str, vector<string>& solution) {
     if (right_count > left_count || left_count > n || right_count > n) {
       return;
     }
     if (left_count == right_count && left_count == n) {
       solution.push_back(str);
       return;
     }
     str.push_back('(');
     backtrack(left_count + 1, right_count, n, str, solution);
     str.pop_back();

     str.push_back(')');
     backtrack(left_count, right_count + 1, n, str, solution);
     str.pop_back();
   }
};
