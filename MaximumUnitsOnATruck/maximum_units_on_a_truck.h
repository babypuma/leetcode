/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/03
 *
 * Source : https://leetcode-cn.com/problems/maximum-units-on-a-truck/
 * Problem: Maximum Units on a Truck
 *               
 */
#include <vector>
using std::vector;

class Sorter {
 public:
   bool operator()(const vector<int>& v1, const vector<int>& v2) {
     return v1[1] > v2[1];
   }
};

class Solution {
 public:
   int maximumUnits(vector<vector<int> >& boxTypes, int truckSize) {
     std::sort(boxTypes.begin(), boxTypes.end(), Sorter());
     int units = 0;
     for (auto& box : boxTypes) {
       if (truckSize > box[0]) {
         truckSize -= box[0];
         units += box[0] * box[1];
       } else {
         units += truckSize * box[1];
         break;
       }
     }
     return units;
   }
};
