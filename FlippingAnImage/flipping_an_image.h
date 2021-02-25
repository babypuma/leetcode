/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/02/24
 *
 * Source : https://leetcode-cn.com/problems/flipping-an-image/
 * Problem: Flipping an Image
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   vector<vector<int> > flipAndInvertImage(vector<vector<int> >& A) {
     int row = A.size();
     int col = A[0].size();
     vector<vector<int> > image(row, vector<int>(col));
     for (int i = 0; i < row; ++i) {
       for (int j = col - 1; j >= 0; --j) {
         image[i][col - 1 - j] = (A[i][j] == 0 ? 1 : 0);
       }
     }
     return image;
   }
};
