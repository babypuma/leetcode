/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/01
 *
 * Source : https://leetcode-cn.com/problems/shortest-way-to-form-string/
 * Problem:	Shortest Way to Form String
 *
 */
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
 public:
   int shortestWay(string source, string target) {
     int idx = 0;
     int count = 0;
     while (idx < target.size()) {
       int tmp = match(source, target, idx);
       if (tmp == idx) {
         return -1;
       }
       idx = tmp;
       ++count;
     }
     return count;
   }

 private:
   int match(string& source, string& target, int i) {
     size_t j = 0;
     while (i < target.size() && j < source.size()) {
       if (target[i] == source[j]) {
         i++;
       }
       j++;
     }
     return i;
   }
};
