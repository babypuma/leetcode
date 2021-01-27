/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/28
 *
 * Source : https://leetcode-cn.com/problems/shortest-path-to-get-food/
 * Problem: Shortest Path to Get Food
 *               
 */
#include <queue>
#include <vector>
using std::queue;
using std::vector;

class Solution {
 public:
   int getFood(vector<vector<char> >& grid) {
     int row = grid.size();
     int col = grid[0].size();
     vector<vector<int> > path(row, vector<int>(col, -1));
     queue<Point> que;
     for (int i = 0; i < row; ++i) {
       for (int j = 0; j < col; ++j) {
         if (grid[i][j] == '*') {
           path[i][j] = 0;
           que.push(Point(i, j));
           break;
         }
       }
     }
     while (!que.empty()) {
       Point p = que.front();
       que.pop();
       if (grid[p.x_][p.y_] == '#') {
         return path[p.x_][p.y_];
       }
       if (p.x_ > 0 && grid[p.x_ - 1][p.y_] != 'X' && path[p.x_ - 1][p.y_] < 0) {
         path[p.x_ - 1][p.y_] = path[p.x_][p.y_] + 1;
         que.push(Point(p.x_ - 1, p.y_));
       }
       if (p.x_ < row - 1 && grid[p.x_ + 1][p.y_] != 'X' && path[p.x_ + 1][p.y_] < 0) {
         path[p.x_ + 1][p.y_] = path[p.x_][p.y_] + 1;
         que.push(Point(p.x_ + 1, p.y_));
       }
       if (p.y_ > 0 && grid[p.x_][p.y_ - 1] != 'X' && path[p.x_][p.y_ - 1] < 0) {
         path[p.x_][p.y_ - 1] = path[p.x_][p.y_] + 1;
         que.push(Point(p.x_, p.y_ - 1));
       }
       if (p.y_ < col - 1 && grid[p.x_][p.y_ + 1] != 'X' && path[p.x_][p.y_ + 1] < 0) {
         path[p.x_][p.y_ + 1] = path[p.x_][p.y_] + 1;
         que.push(Point(p.x_, p.y_ + 1));
       }
     }
     return -1;
   }

 private:
   struct Point {
     int x_;
     int y_;
     Point(int x, int y) : x_(x), y_(y) {}
   };
};
