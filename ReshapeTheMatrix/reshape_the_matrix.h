/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/17
 *
 * Source : https://leetcode-cn.com/problems/reshape-the-matrix/
 * Problem: Reshape The Matrix
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   vector<vector<int> > matrixReshape(vector<vector<int> >& nums, int r, int c) {
     int row = nums.size();
     int col = nums[0].size();
     if (row * col < r * c) {
       return nums;
     }
     vector<vector<int> > matrix(r, vector<int>(c, 0));
     for (int i = 0; i < r; ++i) {
       for (int j = 0; j < c; ++j) {
         int idx = i * c + j;
         matrix[i][j] = nums[idx / col][idx % col];
       }
     }

     return matrix;
   }
};
