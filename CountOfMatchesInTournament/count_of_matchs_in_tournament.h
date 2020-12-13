/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/13
 *
 * Source : https://leetcode-cn.com/problems/count-of-matches-in-tournament/
 * Problem:	Count of Matches in Tournament
 *               
 */
class Solution {
 public:
   int numberOfMatches(int n) {
     if (n <= 1) {
       return 0;
     } else if (n == 2) {
       return 1;
     }
     
     if (n % 2 == 0) {
       n /= 2;
       return n + numberOfMatches(n);
     } else {
       n /= 2;
       return n + numberOfMatches(n + 1);
     }
   }
};
