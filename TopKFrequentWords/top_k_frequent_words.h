/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/12/14
 *
 * Source : https://leetcode-cn.com/problems/top-k-frequent-words/
 * Problem: Top K Frequent Words
 *               
 */
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>
using std::string;
using std::vector;
using std::set;
using std::unordered_map;
using std::priority_queue;

class Solution {
 public:
   vector<string> topKFrequent(vector<string>& words, int k) {
     unordered_map<string, int> word_cnt;
     for (auto& str : words) {
       ++word_cnt[str];
     }
     unordered_map<int, vector<string> > word_rank;
     set<int> cnt_set;
     for (auto& it : word_cnt) {
       word_rank[it.second].push_back(it.first);
       cnt_set.insert(it.second);
     }
     vector<string> top_k;
     priority_queue<int, vector<int>, std::less<int> > que(cnt_set.begin(), cnt_set.end());
     while (top_k.size() < k) {
       int cnt = que.top();
       que.pop();
       if (word_rank[cnt].size() > 1) {
         std::sort(word_rank[cnt].begin(), word_rank[cnt].end());
       }
       int m = std::min(word_rank[cnt].size(), k - top_k.size());
       for (int j = 0; j < m; ++j) {
         top_k.push_back(word_rank[cnt][j]);
       }
     }
     return top_k;
   }
};
