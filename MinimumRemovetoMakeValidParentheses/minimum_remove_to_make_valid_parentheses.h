/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/14
 *
 * Source : https://leetcode-cn.com/problems/minimum-remove-to-make-valid-parentheses/
 * Problem: Minimum Remove to Make Valid Parentheses
 *               
 */
#include <string>
#include <unordered_set>
#include <stack>
using std::string;
using std::unordered_set;
using std::stack;

class Solution {
 public:
   string minRemoveToMakeValid(string s) {
     stack<char> st;
     unordered_set<int> skipped_ch;
     for (int i = 0; i < s.size(); ++i) {
       char ch = s[i];
       if (ch == '(') {
         st.push(ch);
       } else if (ch == ')') {
         if (st.empty()) {
           skipped_ch.insert(i);
         } else {
           st.pop();
         }
       }
     }
     stack<char>().swap(st);
     for (int i = s.size() - 1; i >= 0; --i) {
       char ch = s[i];
       if (ch == '(') {
         if (st.empty()) {
           skipped_ch.insert(i);
         } else {
           st.pop();
         }
       } else if (ch == ')') {
         st.push(ch);
       }
     }

     string valid_str;
     for (int i = 0; i < s.size(); ++i) {
       if (skipped_ch.find(i) == skipped_ch.end()) {
         valid_str += s[i];
       }
     }
     return valid_str;
   }
};
