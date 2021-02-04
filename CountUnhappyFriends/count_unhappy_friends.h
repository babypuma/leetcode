/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/04
 *
 * Source : https://leetcode-cn.com/problems/count-unhappy-friends/
 * Problem: Count Unhappy Friends
 *               
 */
#include <vector>
#include <bitset>
#include <unordered_map>
using std::vector;
using std::bitset;
using std::unordered_map;

class Solution {
 public:
   int unhappyFriends(int n, vector<vector<int> >& preferences, vector<vector<int> >& pairs) {
     vector<vector<int> > friendship(n, vector<int>(n, INT_MAX));
     for (int i = 0; i < preferences.size(); ++i) {
       for (int j = 0; j < preferences[i].size(); ++j) {
         friendship[i][preferences[i][j]] = j;
       }
     }
     unordered_map<int, int> friends;
     for (auto& p : pairs) {
       friends[p[0]] = p[1];
       friends[p[1]] = p[0];
     }

     bitset<PERSON_NUM> unhappy;
     for (int i = 0; i < n; ++i) {
       for (int j = 0; j < n; ++j) {
         if (i == j) {
           continue;
         }
         if (!unhappy.test(i) || !unhappy.test(j)) {
           if (friendship[i][friends[i]] > friendship[i][j] && friendship[j][friends[j]] > friendship[j][i]) {
             unhappy.set(i);
             unhappy.set(j);
           }
         }
       }
     }
     return unhappy.count();
   }

 private:
   static const int PERSON_NUM = 500;
};
