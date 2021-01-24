/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/24
 *
 * Source : https://leetcode-cn.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/
 * Problem: Change Minimum Characters to Satisfy One of Three Conditions
 *               
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 public:
   int minCharacters(string a, string b) {
     vector<int> f1(NUM, 0);
     for (auto& ch : a) {
       ++f1[ch - 'a'];
     }
     vector<int> f2(NUM, 0);
     for (auto& ch : b) {
       ++f2[ch - 'a'];
     }

     vector<int> ac1(NUM, 0);
     vector<int> ac2(NUM, 0);
     ac1[0] = f1[0];
     ac2[0] = f2[0];
     for (size_t i = 1; i < NUM; ++i) {
       ac1[i] += ac1[i - 1] + f1[i];
       ac2[i] += ac2[i - 1] + f2[i];
     }

     int ans = ac1.back() + ac2.back();
     for (size_t i = 0; i < NUM - 1; ++i) {
       ans = std::min(ac1.back() - ac1[i] + ac2[i], ans);
       ans = std::min(ac2.back() - ac2[i] + ac1[i], ans);
     }
     for (size_t i = 0; i < NUM; ++i) {
       ans = std::min(ac1.back() + ac2.back() - f1[i] - f2[i], ans);
     }
     return ans;
   }

 private:
   static const int NUM = 26;
};
