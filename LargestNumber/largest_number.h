/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/17
 *
 * Source : https://leetcode-cn.com/problems/largest-number/
 * Problem: Largest Number
 *               
 */
#include <string>
#include <vector>
#include <cstring>
using std::string;
using std::vector;

class IntComparator {
 public:
  bool operator()(const int& i1, const int& i2) {
    return internalComparator(std::to_string(i1), std::to_string(i2));
  }

 private:
  bool internalComparator(const string& s1, const string& s2) {
    int sz = std::min(s1.size(), s2.size());
    int res = strncmp(s1.c_str(), s2.c_str(), sz);
    if (s1.size() == s2.size() || res != 0) {
      return res > 0;
    }

    if (s1.size() < s2.size()) {
      return internalComparator(s1, s2.substr(sz));
    } else {
      return internalComparator(s1.substr(sz), s2);
    }
  }
};

class Solution {
 public:
   string largestNumber(vector<int>& nums) {
     std::sort(nums.begin(), nums.end(), IntComparator());
     if (nums[0] == 0) {
       return "0";
     }
     string num;
     for (auto& i : nums) {
       num += std::to_string(i);
     }
     return num;
   }
};
