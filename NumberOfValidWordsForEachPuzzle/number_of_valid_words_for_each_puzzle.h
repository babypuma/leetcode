/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/26
 *
 * Source : https://leetcode-cn.com/problems/number-of-valid-words-for-each-puzzle/
 * Problem: Number of Valid Words for Each Puzzle
 *               
 */
#include <string>
#include <vector>
#include <unordered_map>
using std::string;
using std::vector;
using std::unordered_map;

class Solution {
 public:
   vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
     unordered_map<int, int> freq;
     for (auto& w : words) {
       int key = 0;
       for (auto& ch : w) {
         key |= (1 << (ch - 'a'));
       }
       if (__builtin_popcount(key) <= PUZZLE_LENGTH) {
         ++freq[key];
       }
     }

     vector<int> nums;
     for (auto& p : puzzles) {
       int mask = 0;
       for (size_t i = 1; i < PUZZLE_LENGTH; ++i) {
         mask |= (1 << (p[i] - 'a'));
       }

       int num = 0;
       int subset = mask;
       do {
         int s = subset | (1 << (p[0] - 'a'));
         if (freq.count(s) != 0) {
           num += freq[s];
         }
         subset = (subset - 1) & mask;
       } while (subset != mask);
       nums.push_back(num);
     }
     return nums;
   }

 private:
   static const int PUZZLE_LENGTH = 7;
};
