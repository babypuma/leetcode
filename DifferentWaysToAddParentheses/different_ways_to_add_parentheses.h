/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/13
 *
 * Source : https://leetcode-cn.com/problems/different-ways-to-add-parentheses/
 * Problem: Different Ways to Add Parentheses
 *               
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
 public:
   vector<int> diffWaysToCompute(string input) {
     vector<int> nums;
     vector<char> ops;
     parseExpression(input, nums, ops);
     return diffWaysToCompute(nums, ops, 0, nums.size() - 1);
   }

 private:
   void parseExpression(string& input, vector<int>& nums, vector<char>& ops) {
     int num = 0;
     for (size_t i = 0; i < input.size(); ++i) {
       if (isdigit(input[i])) {
         num = 10 * num + (input[i] - '0');
       } else {
         nums.push_back(num);
         num = 0;
         ops.push_back(input[i]);
       }
     }
     nums.push_back(num);
   }

   vector<int> diffWaysToCompute(vector<int>& nums, vector<char>& ops, int left, int right) {
     vector<int> ans;
     if (left == right) {
       ans.push_back(nums[left]);
       return ans;
     }

     for (int i = left; i < right; ++i) {
       vector<int> v1 = diffWaysToCompute(nums, ops, left, i);
       vector<int> v2 = diffWaysToCompute(nums, ops, i + 1, right);
       for (auto& n1 : v1) {
         for (auto& n2 : v2) {
           switch (ops[i]) {
             case '+':
               ans.push_back(n1 + n2);
               break;
             case '-':
               ans.push_back(n1 - n2);
               break;
             case '*':
               ans.push_back(n1 * n2);
               break;
           }
         }
       }
     }

     return ans;
   }
};
