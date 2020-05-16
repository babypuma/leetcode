#include <string>
using std::string;

class Solution {
 public:
   string longestPalindrome(string s) {
     string s1 = longestPalindromePattern1(s);
     string s2 = longestPalindromePattern2(s);
     return s1.size() >= s2.size() ? s1 : s2;
   }

 private:
   string longestPalindromePattern1(string& s) {
     int idx = 0;
     int radius = 0;
     for (size_t i = 0; i < s.size(); ++i) {
       int r = expandPalindromePattern1(s, i);
       if (r > radius) {
         radius = r;
         idx = i;
       }
     }
     return s.substr(idx - radius, 2 * radius + 1);
   }

   int expandPalindromePattern1(string& s, int idx) {
     int radius = 0;
     int left = idx;
     int right = idx;
     while (left >= 0 &&
            right <= static_cast<int>(s.size() - 1) &&
            s[left] == s[right]) {
       left--;
       right++;
       radius++;
     }
     return radius - 1;
   }

   string longestPalindromePattern2(string& s) {
     int idx = 0;
     int radius = 0;
     for (size_t i = 0; i < s.size(); ++i) {
       int r = expandPalindromePattern2(s, i);
       if (r > radius) {
         radius = r;
         idx = i;
       }
     }
     if (radius == 0) {
       return string();
     } else {
       return s.substr(idx - radius + 1, 2 * radius);
     }
   }

   int expandPalindromePattern2(string& s, int idx) {
     int radius = 0;
     int left = idx;
     int right = idx + 1;
     while (left >= 0 &&
            right <= static_cast<int>(s.size() - 1) &&
            s[left] == s[right]) {
       left--;
       right++;
       radius++;
     }
     return radius;
   }
};
