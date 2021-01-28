/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/29
 *
 * Source : https://leetcode-cn.com/problems/path-with-minimum-effort/
 * Problem: Path With Minimum Effort
 *               
 */
#include <queue>
#include <vector>
using std::vector;
using std::priority_queue;

struct Point {
  int x;
  int y;
  Point(int x_, int y_) : x(x_), y(y_) {}
};

struct Edge {
  int weight;
  Point dest;
  Edge(int w, int x, int y) : weight(w), dest(x, y) {}
};

class Comparator {
 public:
   bool operator()(const Edge& e1, const Edge& e2) {
     return e1.weight > e2.weight;
   }
};

class Solution {
 public:
   int minimumEffortPath(vector<vector<int> >& heights) {
     int row = heights.size();
     int col = heights[0].size();
     vector<vector<bool> > visited(row, vector<bool>(col, false));
     priority_queue<Edge, vector<Edge>, Comparator> que;
     visited[0][0] = true;
     if (row > 1) {
       que.push(Edge(std::abs(heights[0][0] - heights[1][0]), 1, 0));
     }
     if (col > 1) {
       que.push(Edge(std::abs(heights[0][0] - heights[0][1]), 0, 1));
     }
     int ans = 0;
     while (!que.empty()) {
       Edge e = que.top();
       que.pop();
       ans = std::max(ans, e.weight);
       int x = e.dest.x;
       int y = e.dest.y;
       if (x == row - 1 && y == col - 1) {
         break;
       }
       visited[x][y] = true;
       if (x > 0 && !visited[x - 1][y]) {
         que.push(Edge(std::abs(heights[x][y] - heights[x - 1][y]), x - 1, y));
       }
       if (x < row - 1 && !visited[x + 1][y]) {
         que.push(Edge(std::abs(heights[x][y] - heights[x + 1][y]), x + 1, y));
       }
       if (y > 0 && !visited[x][y - 1]) {
         que.push(Edge(std::abs(heights[x][y] - heights[x][y - 1]), x, y - 1));
       }
       if (y < col - 1 && !visited[x][y + 1]) {
         que.push(Edge(std::abs(heights[x][y] - heights[x][y + 1]), x, y + 1));
       }
     }
     return ans;
   }
};
