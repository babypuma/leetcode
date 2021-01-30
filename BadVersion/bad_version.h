/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/29
 *
 * Source : https://leetcode-cn.com/problems/first-bad-version/
 * Problem: First Bad Version
 *               
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

bool isBadVersion(int version);

class Solution {
 public:
   int firstBadVersion(int n) {
     return binarySearch(1, n);
   }

 private:
   int binarySearch(int l, int r) {
     if (l == r) {
       return l;
     }
     int mid = l + (r - l) / 2;
     if (isBadVersion(mid)) {
       return binarySearch(l, mid);
     } else {
       return binarySearch(mid + 1, r);
     }
   }
};
