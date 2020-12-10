/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/11
 *
 * Source : https://leetcode-cn.com/problems/valid-palindrome-ii/
 * Problem:	Valid Palindrome II
 *               
 */
#include <string>
using std::string;

class Solution {
 public:
   bool validPalindrome(string s) {
     int left = 0;
     int right = s.size() - 1;
     while (left < right) {
       if (s[left] != s[right]) {
         return valid(s, left, right - 1) || valid(s, left + 1, right);
       }
       ++left;
       --right;
     }

     return true;
   }

 private:
   bool valid(string s, int left, int right) {
     while (left < right) {
       if (s[left] != s[right]) {
         return false;
       }
       ++left;
       --right;
     }
     return true;
   }
};
