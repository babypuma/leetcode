/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/13
 *
 * Source : https://leetcode-cn.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
 * Problem:	Partitioning Into Minimum Number Of Deci-Binary Numbers
 *               
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 public:
   int minPartitions(string n) {
     vector<int> num(10, 0);
     int ans = 0;
     for (size_t i = 0; i < n.size(); ++i) {
       ans = std::max(ans, n[i] - '0');
     }
     return ans;
   }
};
