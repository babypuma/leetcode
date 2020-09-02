/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/02
 *
 * Source : https://leetcode.com/problems/count-numbers-with-unique-digits/
 * Problem:	Count Numbers with Unique Digits
 *
 */
#include <vector>

using std::vector;

class Solution {
 public:
   Solution() {
     vec1.reserve(9);
     vec1[0] = 0;
     vec1[1] = 10;
     for (size_t i = 2; i < 9; ++i) {
       vec1[i] = vec1[i - 1] * (11 - i);
     }

     vec2.reserve(9);
     vec2[0] = 0;
     vec2[1] = 0;
     vec2[2] = 9;
     for (size_t i = 3; i < 9; ++i) {
       vec2[i] = vec2[i - 1] * (11 - i);
     }

     for (size_t i = 1; i < 9; ++i) {
       vec1[i] += vec1[i - 1];
       vec2[i] += vec2[i - 1];
     }
   }

   int countNumbersWithUniqueDigits(int n) {
     return (n == 0) ? 1 : vec1[n] - vec2[n];
   }

 private:
   vector<int> vec1;
   vector<int> vec2;
};
