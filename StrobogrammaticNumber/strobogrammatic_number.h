/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/29
 *
 * Source : https://leetcode-cn.com/problems/strobogrammatic-number/
 * Problem: Strobogrammatic Number
 *               
 */
#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

class Solution {
 public:
   bool isStrobogrammatic(string num) {
     int left = 0;
     int right = num.size() - 1;
     unordered_map<char, char> mp;
     mp['6'] = '9';
     mp['9'] = '6';
     mp['0'] = '0';
     mp['1'] = '1';
     mp['8'] = '8';
     while (left <= right) {
       if (mp.count(num[left]) == 0 || mp[num[left]] != num[right]) {
         return false;
       }
       ++left;
       --right;
     }
     return true;
   }
};
