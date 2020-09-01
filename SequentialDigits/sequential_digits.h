/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/01
 *
 * Source : https://leetcode.com/problems/sequential-digits/
 * Problem:	Sequential Digits
 *
 */
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
   vector<int> sequentialDigits(int low, int high) {
     const string space = "123456789";
     string low_str = std::to_string(low);
     string high_str = std::to_string(high);
     vector<int> solution;
     for (size_t i = low_str.size(); i <= high_str.size(); ++i) {
       iteration(space, low_str, high_str, i, solution);
     }
     sort(solution.begin(), solution.end());
     return solution;
   }

 private:
   void iteration(const string& space, const string& low, const string& high, size_t length, vector<int>& solution) {
     for (size_t i = 0; i < space.size() - length + 1; ++i) {
       string str = space.substr(i, length);
       if (myCompare(str, low) >= 0 && myCompare(str, high) <= 0) {
         solution.push_back(stoi(str));
       }
     }
   }

   int myCompare(const string& left, const string& right) {
     if (left.size() == right.size()) {
       return left.compare(right);
     }
     return left.size() < right.size() ? -1 : 1;
   }
};
