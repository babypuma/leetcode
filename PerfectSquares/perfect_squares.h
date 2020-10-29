/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/29
 *
 * Source : https://leetcode-cn.com/problems/perfect-squares/
 * Problem:	Perfect Squares
 *
 */
#include <unordered_map>
#include <cmath>
using std::unordered_map;

class Solution {
 public:
   int numSquares(int n) {
     unordered_map<int, int> cache;
     for (int i = 1; ; ++i) {
       int square = i * i;
       if (square > n) {
         break;
       }
       cache[square] = 1;
     }

     return numSquares(n, cache);
   }

 private:
   int numSquares(int n, unordered_map<int, int>& cache) {
     if (cache.find(n) != cache.end()) {
       return cache[n];
     }
     int num = n;
     int start = floor(sqrt(n));
     for (int i = start; i > 1; --i) {
       int square = i * i;
       if (num == 2 || n / square > num) {
         break;
       }
       int tmp = numSquares(square, cache) + numSquares(n - square, cache);
       num = std::min(num, tmp);
     }
     return cache[n] = num;
   }
};
