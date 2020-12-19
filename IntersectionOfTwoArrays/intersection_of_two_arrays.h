/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/14
 *
 * Source : https://leetcode-cn.com/problems/intersection-of-two-arrays/
 * Problem: Intersection of Two Arrays
 *               
 */
#include <unordered_set>
#include <vector>
using std::unordered_set;
using std::vector;

class Solution {
 public:
   vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
     unordered_set<int> uniq(nums1.begin(), nums1.end());
     unordered_set<int> comm;
     for (auto& n : nums2) {
       if (uniq.find(n) != uniq.end()) {
         comm.insert(n);
       }
     }
     return vector<int>(comm.begin(), comm.end());
   }
};
