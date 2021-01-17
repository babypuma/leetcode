/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/07
 *
 * Source : https://leetcode-cn.com/problems/check-if-it-is-a-straight-line/
 * Problem: Check If It Is a Straight Line
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   bool checkStraightLine(vector<vector<int> >& coordinates) {
     vector<int>& p1 = coordinates[0];
     int x1 = p1[0];
     int y1 = p1[1];
     vector<int>& p2 = coordinates[1];
     int x2 = p2[0];
     int y2 = p2[1];
     if (x1 == x2) {
       for (auto& p : coordinates) {
         if (p[0] != x2) {
           return false;
         }
       }
       return true;
     }

     double k = static_cast<double>(y1 - y2) / (x1 - x2);
     double b = y1 - k * x1;
     for (size_t i = 2; i < coordinates.size(); ++i) {
       vector<int>& p = coordinates[i];
       int x = p[0];
       int y = p[1];
       if (y != k * x + b) {
         return false;
       }
     }
     return true;
   }
};
