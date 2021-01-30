/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/30
 *
 * Source : https://leetcode-cn.com/problems/swim-in-rising-water/
 * Problem: Swim in Rising Water
 *               
 */
#include <vector>
#include <queue>
using std::vector;
using std::priority_queue;

struct Point {
  int x;
  int y;
  int weight;
  Point(int x_, int y_, int w_) : x(x_), y(y_), weight(w_) {}
};

class Comparator {
 public:
   bool operator()(const Point& p1, const Point& p2) {
     return p1.weight > p2.weight;
   }
};

class Solution {
 public:
   int swimInWater(vector<vector<int> >& grid) {
     int sz = grid.size();
     vector<vector<bool> > visited(sz, vector<bool>(sz, false));
     priority_queue<Point, vector<Point>, Comparator> que;
     que.push(Point(0, 0, grid[0][0]));
     int t = 0;
     while (!que.empty()) {
       Point p = que.top();
       que.pop();
       visited[p.x][p.y] = true;
       t = std::max(t, p.weight);
       if (p.x == sz - 1 && p.y == sz - 1) {
         break;
       }
       if (p.x > 0 && !visited[p.x - 1][p.y]) {
         que.push(Point(p.x - 1, p.y, grid[p.x - 1][p.y]));
       }
       if (p.y > 0 && !visited[p.x][p.y - 1]) {
         que.push(Point(p.x, p.y - 1, grid[p.x][p.y - 1]));
       }
       if (p.x < sz - 1 && !visited[p.x + 1][p.y]) {
         que.push(Point(p.x + 1, p.y, grid[p.x + 1][p.y]));
       }
       if (p.y < sz - 1 && !visited[p.x][p.y + 1]) {
         que.push(Point(p.x, p.y + 1, grid[p.x][p.y + 1]));
       }
     }
     return t;
   }
};
