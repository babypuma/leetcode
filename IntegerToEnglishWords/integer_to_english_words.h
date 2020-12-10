/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/10
 *
 * Source : https://leetcode-cn.com/problems/integer-to-english-words/
 * Problem:	Integer to English Words
 *               
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

static const string unit[4] = {"", "Thousand", "Million", "Billion"};
static const string first_bit[21] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
static const string second_bit[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

class Solution {
 public:
   string numberToWords(int num) {
     if (num == 0) {
       return "Zero";
     }

     int i = 0;
     vector<string> words;
     while (num > 0) {
       string str = basicNumber(num % 1000);
       string ut = unit[i];
       if (!str.empty()) {
         if (!ut.empty()) {
           str.append(" ");
           str.append(ut);
         }
         words.push_back(str);
       }
       ++i;
       num /= 1000;
     }

     std::reverse(words.begin(), words.end());
     string s;
     for (int i = 0; i < words.size() - 1; ++i) {
       s.append(words[i]);
       s.append(" ");
     }
     s.append(words.back());
     return s;
   }

 private:
   string basicNumber(int num) {
     string str;
     if (num == 0) {
       return str; 
     }

     if (num / 100 > 0) {
       str.append(first_bit[num / 100]);
       str.append(" ");
       str.append("Hundred");
     }

     num %= 100;
     if (num >= 20) {
       str.empty() ? str.append("") : str.append(" ");
       str.append(second_bit[num / 10]);
       num %= 10;
       if (num > 0) {
         str.empty() ? str.append("") : str.append(" ");
         str.append(first_bit[num]);
       }
     } else if (num > 0) {
       str.empty() ? str.append("") : str.append(" ");
       str.append(first_bit[num]);
     }

     return str;
   }
};
