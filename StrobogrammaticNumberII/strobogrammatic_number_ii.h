/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/29
 *
 * Source : https://leetcode-cn.com/problems/strobogrammatic-number-ii/
 * Problem: Strobogrammatic Number II
 *               
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 public:
   vector<string> findStrobogrammatic(int n) {
     char ch[] = {'0', '1', '6', '9', '8'};
     vector<char> v(ch, ch + sizeof(ch) / sizeof(char));
     vector<string> solution;
     string candidate(n, ' ');
     backtrack(n, 0, v, candidate, solution);
     return solution;
   }

 private:
   void backtrack(int n, int start, vector<char>& v, string& candidate, vector<string>& solution) {
     if (start >= (n + 1) / 2) {
       solution.push_back(candidate);
       return;
     }
     for (size_t i = 0; i < v.size(); ++i) {
       if (start == 0 && n > 1 && v[i] == '0') {
         continue;
       }
       if (start == n - 1 - start && (v[i] == '6' || v[i] == '9')) {
         continue;
       }
       candidate[start] = v[i];
       switch (v[i]) {
         case '0':
         case '1':
         case '8':
           candidate[n - start - 1] = v[i];
           break;
         case '6':
           candidate[n - start - 1] = '9';
           break;
         case '9':
           candidate[n - start - 1] = '6';
           break;
       }
       backtrack(n, start + 1, v, candidate, solution);
     }
   }
};
