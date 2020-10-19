/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/19
 *
 * Source : https://leetcode-cn.com/problems/masking-personal-information/
 * Problem:	Masking Personal Information
 *
 */
#include <vector>
#include <string>
#include <cctype>
using std::vector;
using std::string;

class Solution {
 public:
   string maskPII(string S) {
     string dest;
     if (maskEmailAddress(S, dest)) {
       return dest;
     } else if (maskPhoneNumber(S, dest)) {
       return dest;
     }
     return S;
   }

 private:
   bool maskEmailAddress(string& s, string& dest) {
     dest.clear();
     size_t pos1 = s.find('@');
     if (pos1 == string::npos || pos1 < 2) {
       return false;
     }
     size_t pos2 = s.find('.', pos1);
     if (pos2 == string::npos || pos2 == s.size() - 1) {
       return false;
     }
     for (size_t i = 0; i < pos1; ++i) {
       if (!isalpha(s[i])) {
         return false;
       }
     }
     dest.append(1, tolower(s[0]));
     dest.append("*****");
     dest.append(1, tolower(s[pos1 - 1]));
     dest.append("@");
     for (size_t i = pos1 + 1; i < pos2; ++i) {
       if (!isalpha(s[i])) {
         return false;
       }
       dest.append(1, tolower(s[i]));
     }
     dest.append(".");
     for (size_t i = pos2 + 1; i < s.size(); ++i) {
       if (!isalpha(s[i])) {
         return false;
       }
       dest.append(1, tolower(s[i]));
     }
     return true;
   }

   bool maskPhoneNumber(string& s, string& dest) {
     dest.clear();
     vector<char> phone_num;
     for (size_t i = 0; i < s.size(); ++i) {
       if (s[i] == '+' || s[i] == '-' || s[i] == '(' || s[i] == ')' || s[i] == ' ') {
         continue;
       }
       if (!isdigit(s[i])) {
         return false;
       }
       phone_num.push_back(s[i]);
     }
     if (phone_num.size() < 10 || phone_num.size() > 13) {
       return false;
     }
     if (phone_num.size() > 10) {
       dest.append("+");
       dest.append(phone_num.size() - 10, '*');
       dest.append("-");
     }
     dest.append("***-***-");
     for (int i = phone_num.size() - 4; i < phone_num.size(); ++i) {
       dest.append(1, phone_num[i]);
     }
     return true;
   }
};
