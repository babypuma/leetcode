/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/02
 *
 * Source : https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
 * Problem:	Search a 2D Matrix II
 *
 */
#include <vector>
using std::vector;

class Solution {
 public:
   bool searchMatrix(vector<vector<int> >& matrix, int target) {
     if (matrix.empty() || matrix[0].empty()) {
       return false;
     }
     return search(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1, target);
   }

 private:
   bool search(vector<vector<int> >& matrix, int y1, int x1, int y2, int x2, int target) {
     if (y1 > y2 || x1 > x2) {
       return false;
     }
     if (matrix[y1][x1] > target || matrix[y2][x2] < target) {
       return false;
     }
     if (x1 == x2 && y1 == y2) {
       return matrix[y1][x1] == target;
     }
     return
       search(matrix, y1, x1, (y1 + y2)/2, (x1 + x2)/2, target) ||
       search(matrix, y1, (x1 + x2)/2 + 1, (y1 + y2)/2, x2, target) ||
       search(matrix, (y1 + y2)/2 + 1, (x1 + x2)/2 + 1, y2, x2, target) ||
       search(matrix, (y1 + y2)/2 + 1, x1, y2, (x1 + x2)/2, target);
   }
};
