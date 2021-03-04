/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/03/04
 *
 * Source : https://leetcode-cn.com/problems/number-of-connected-components-in-an-undirected-graph/
 * Problem: Number of Connected Components in an Undirected Graph
 *               
 */
#include <vector>
#include <list>
using std::vector;
using std::list;

class Solution {
 public:
   int countComponents(int n, vector<vector<int> >& edges) {
     vector<list<int> > graph(n);
     for (auto& e : edges) {
       int u = e[0];
       int v = e[1];
       graph[u].insert(graph[u].begin(), v);
       graph[v].insert(graph[v].begin(), u);
     }

     vector<bool> visited(n, false);
     int count = 0;
     for (int i = 0; i < n; ++i) {
       if (visited[i]) {
         continue;
       }
       dfs(graph, i, visited);
       ++count;
     }
     return count;
   }

 private:
   void dfs(const vector<list<int> >& graph, int start, vector<bool>& visited) {
     visited[start] = true;
     for (auto& v : graph[start]) {
       if (!visited[v]) {
         dfs(graph, v, visited);
       }
     }
   }
};
