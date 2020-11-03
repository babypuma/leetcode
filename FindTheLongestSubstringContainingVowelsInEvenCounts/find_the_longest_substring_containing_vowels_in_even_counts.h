/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/11/04
 *
 * Source : https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
 * Problem:	Find the Longest Substring Containing Vowels in Even Counts
 *
 */
#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

class Solution {
 public:
   int findTheLongestSubstring(string s) {
     int checksum = 0;
     int ans = 0;
     unordered_map<int, int> prefix_sum;
     for (int i = 0; i < s.size(); ++i) {
       setChecksum(s[i], checksum);
       if (checksum == 0) {
         ans = std::max(ans, i + 1);
       }
       if (prefix_sum.count(checksum) > 0) {
         ans = std::max(ans, i - prefix_sum[checksum]);
       } else {
         prefix_sum[checksum] = i;
       }
     }

     return ans;
   }

 private:
   void setChecksum(char ch, int& checksum) {
     int mask = 0;
     switch (ch) {
       case 'a':
         mask = 1 << 1;
         break;
       case 'e':
         mask = 1 << 2;
         break;
       case 'i':
         mask = 1 << 3;
         break;
       case 'o':
         mask = 1 << 4;
         break;
       case 'u':
         mask = 1 << 5;
         break;
       default:
         break;
     }
     if (mask == 0) {
       return;
     }
     checksum = (checksum & ~mask) | (~(checksum & mask) & mask);
   }
};
