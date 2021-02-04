/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/04
 *
 * Source : https://leetcode-cn.com/problems/longest-repeating-character-replacement/
 * Problem: Longest Repeating Character Replacement
 *               
 */
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
 public:
   int characterReplacement(string s, int k) {
     int sz = s.size();
     if (sz < 2) {
       return sz;
     }
     vector<int> freq(NUM, 0);
     int left = 0;
     int right = 0;
     int max_length = 0;
     int ans = 0;
     while (right < sz) {
       ++freq[s[right] - 'A'];
       max_length = std::max(max_length, freq[s[right] - 'A']);
       right++;
       if (right - left > max_length + k) {
         --freq[s[left] - 'A'];
         left++;
       }
       ans = std::max(ans, right - left);
     }
     return ans;
   }

 private:
   static const int NUM = 26;
};
