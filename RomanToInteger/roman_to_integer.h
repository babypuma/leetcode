/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/16
 *
 * Source : https://leetcode-cn.com/problems/roman-to-integer/
 * Problem: Roman to Integer
 *               
 */
#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

class Solution {
 public:
   int romanToInt(string s) {
     unordered_map<string, int> injection;
     injection["IV"] = 4;
     injection["IX"] = 9;
     injection["XL"] = 40;
     injection["XC"] = 90;
     injection["CD"] = 400;
     injection["CM"] = 900;
     int num = 0;
     int i = 0;
     int sz = s.size();
     while (i < sz) {
       if (i < sz - 1 && injection.find(s.substr(i, 2)) != injection.end()) {
         num += injection[s.substr(i, 2)];
         i += 2;
       } else {
         switch (s[i]) {
           case 'I':
             num += 1;
             break;
           case 'V':
             num += 5;
             break;
           case 'X':
             num += 10;
             break;
           case 'L':
             num += 50;
             break;
           case 'C':
             num += 100;
             break;
           case 'D':
             num += 500;
             break;
           case 'M':
             num += 1000;
             break;
         }
         ++i;
       }
     }

     return num;
   }
};
