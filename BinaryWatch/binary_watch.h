/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/06/29
 *
 * Source : https://leetcode.com/problems/binary-watch/
 * Problem:	Binary Watch
 */
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
   vector<string> readBinaryWatch(int num) {
     num_ = num;
     solution_.clear();
     vector<int> candidates;
     for (int i = 0; i <= MAXBIT; ++i) {
       candidates.push_back(i);
     }
     vector<int> solution;
     backtrack(0, candidates, solution);
     return solution_;
   }

 private:
   void backtrack(int start, const vector<int>& candidates, vector<int>& solution) {
     if (!isValid(solution)) {
       return;
     }
     if (solution.size() == num_) {
       solution_.push_back(toHour(solution));
       return;
     }

     for (int i = start; i < candidates.size(); ++i) {
       solution.push_back(candidates[i]);
       backtrack(i + 1, candidates, solution);
       solution.pop_back();
     }
   }

   bool isValid(const vector<int>& solution) {
     int bitmap = 0;
     for (size_t i = 0; i < solution.size(); ++i) {
        bitmap |= (1 << solution[i]);
     }
     int hour = (bitmap >> 6);
     int min = (bitmap & 0x3F);
     return hour < 12 && min < 60;
   }

   string toHour(vector<int>& solution) {
     int bitmap = 0;
     for (size_t i = 0; i < solution.size(); ++i) {
        bitmap |= (1 << solution[i]);
     }
     int hour = (bitmap >> 6);
     int min = (bitmap & 0x3F);
     char tm[8];
     sprintf(tm, "%d:%02d", hour, min);
     return string(static_cast<char*>(tm));
   }

 private:
   static const int MAXBIT = 9;
   int num_;
   vector<string> solution_;
};
