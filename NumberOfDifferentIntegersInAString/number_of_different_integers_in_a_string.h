/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/28
 *
 * Source : https://leetcode-cn.com/problems/number-of-different-integers-in-a-string/
 * Problem: Number of Different Integers in a String
 *               
 */
#include <unordered_set>
#include <string>
using std::unordered_set;
using std::string;

class Solution {
 public:
   int numDifferentIntegers(string word) {
     unordered_set<string> uniq;
     int sz = word.size();
     int left = 0;
     int right = 0;
     while (left < sz) {
       if (!isdigit(word[left])) {
         ++left;
         continue;
       }
       right = left;
       while (right < sz && isdigit(word[right])) {
         ++right;
       }
       while (word[left] == '0' && left < right) {
         ++left;
       }
       uniq.insert(word.substr(left, right - left));
       left = right;
     }
     return uniq.size();
   }
};
