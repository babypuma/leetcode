/*
 * Author : Jimmy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2022/05/29
 *
 * Source : https://leetcode.cn/contest/weekly-contest-295/problems/apply-discount-to-prices/
 * Problem:	Apply Discount to Prices
 *
 */
#include <string>
#include <cstdlib>
using std::string;

class Solution {
 public:
   string discountPrices(string sentence, int discount) {
     string s;
     size_t i = 0;
     while (i < sentence.size()) {
       size_t j = i;
       while (j < sentence.size() && sentence[j] != ' ') {
         ++j;
       }
       string word = sentence.substr(i, j - i);
       if (!s.empty()) {
         s.append(" ");
       }
       if (isPrice(word)) {
         s.append(newPrice(word, discount));
       } else {
         s.append(word);
       }

       i = j + 1;
     }

     return s;
   }

 private:
   bool isPrice(string word) {
     if (word.size() <= 1 || word[0] != '$') {
       return false;
     }
     for (size_t i = 1; i < word.size(); ++i) {
       if (word[i] < '0' || word[i] > '9') {
         return false;
       }
     }
     return true;
   }

   string newPrice(string price, int discount) {
      double d1 = strtod(price.substr(1).c_str(), NULL);
      double d2 = 0.01 * d1 * (100 - discount);
      const int SZ = 20;
      char buffer[SZ + 1];
      buffer[0] = '$';
      snprintf(buffer + 1, SZ, "%.2f", d2);
      return buffer;
   }
};
