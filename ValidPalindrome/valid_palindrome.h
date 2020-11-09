/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/30
 * Update : 2020/11/09
 *
 * Source : https://leetcode-cn.com/problems/valid-palindrome/
 * Problem:	Valid Palindrome 
 *
 */
#include <string>
#include <cctype>
using std::string;

class Solution {
 public:
   bool isPalindrome(string s) {
     int left = 0;
     int right = s.size() - 1;
     while (left < right) {
       while (left <= right && !isalnum(s[left])) {
         left++;
       }
       while (left <= right && !isalnum(s[right])) {
         right--;
       }
       if (left < right && tolower(s[left++]) != tolower(s[right--])) {
         return false;
       }
     }
     return true;
   }
};
