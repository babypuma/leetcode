/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/19
 *
 * Source : https://leetcode-cn.com/problems/design-compressed-string-iterator/
 * Problem: Design Compressed String Iterator
 *               
 */
#include <string>
using std::string;

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
class StringIterator {
 public:
   StringIterator(string compressedString) : str(compressedString), str_idx(0), ch_sz(0), ch_cnt(0) {
     size_t i = str_idx + 1;
     while (i < str.size() && isdigit(str[i])) {
       ch_sz *= 10;
       ch_sz += str[i] - '0';
       ++i;
     }
   }

   char next() {
     if (ch_cnt == ch_sz) {
       ++str_idx;
       while (str_idx < str.size() && !isalpha(str[str_idx])) {
         ++str_idx;
       }

       ch_sz = 0;
       ch_cnt = 0;
       size_t i = str_idx + 1;
       while (i < str.size() && isdigit(str[i])) {
         ch_sz *= 10;
         ch_sz += str[i] - '0';
         ++i;
       }
     }

     if (str_idx < str.size()) {
       ++ch_cnt;
       return str[str_idx];
     }
     return ' ';
   }

   bool hasNext() {
     if (ch_cnt < ch_sz) {
       return true;
     }
     size_t i = str_idx + 1;
     while (i < str.size() && !isalpha(str[i])) {
       ++i;
     }
     return i < str.size();
   }

 private:
   string str;
   size_t str_idx;
   size_t ch_sz;
   size_t ch_cnt;
};
