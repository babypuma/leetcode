/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/19
 *
 * Source : https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/
 * Problem: Intersection of Two Arrays II
 *               
 */
#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;

class Solution {
 public:
   vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
     unordered_map<int, int> mp;
     for (auto& n : nums1) {
       ++mp[n];
     }

     vector<int> comm;
     for (auto& n : nums2) {
       if (mp.find(n) != mp.end() && mp[n] > 0) {
         --mp[n];
         comm.push_back(n);
       }
     }
     return comm;
   }
};
