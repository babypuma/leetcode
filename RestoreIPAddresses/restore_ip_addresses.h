/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/03
 *
 * Source : https://leetcode.com/problems/restore-ip-addresses/
 * Problem:	Restore IP Addresses
 *
 */
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
 public:
   vector<string> restoreIpAddresses(string s) {
     vector<string> solution;
     if (s.size() < 4 || s.size() > 12) {
       return solution;
     }
     vector<int> index;
     for (int i = 1; i < s.size(); ++i) {
       index.push_back(i);
     }
     vector<int> candidate;
     candidate.push_back(0);
     backtrack(0, s, index, candidate, solution);
     return solution;
   }

 private:
   void backtrack(int start, const string& s, vector<int>& index, vector<int>& candidate, vector<string>& solution) {
     if (candidate.size() == 4) {
       string ip;
       if (isValidIpAddr(s, candidate, ip)) {
         solution.push_back(ip);
       }
       return;
     }
     for (size_t i = start; i < index.size(); ++i) {
       if (index[i] - candidate.back() > 3) {
         return;
       }
       candidate.push_back(index[i]);
       backtrack(i + 1, s, index, candidate, solution);
       candidate.pop_back();
     }
   }

   bool isValidIpAddr(const string& s, vector<int>& candidate, string& ip) {
     if (candidate.size() != 4) {
       return false;
     }
     string seg = s.substr(candidate[0], candidate[1] - candidate[0]);
     if (isValidIpSegment(seg)) {
       ip.append(seg).append(".");
     } else {
       return false;
     }
     seg = s.substr(candidate[1], candidate[2] - candidate[1]);
     if (isValidIpSegment(seg)) {
       ip.append(seg).append(".");
     } else {
       return false;
     }
     seg = s.substr(candidate[2], candidate[3] - candidate[2]);
     if (isValidIpSegment(seg)) {
       ip.append(seg).append(".");
     } else {
       return false;
     }
     seg = s.substr(candidate[3], s.size() - candidate[3]);
     if (isValidIpSegment(seg)) {
       ip.append(seg);
     } else {
       return false;
     }
     return true;
   }

   bool isValidIpSegment(const string& str) {
     if (str.size() > 1 && str[0] == '0') {
       return false;
     }
     return std::stoi(str) < 256;
   }
};
