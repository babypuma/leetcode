/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/24
 *
 * Source : https://leetcode-cn.com/problems/find-kth-largest-xor-coordinate-value/
 * Problem: Find Kth Largest XOR Coordinate Value
 *               
 */
#include <vector>
using std::vector;

class Solution {
 public:
   int kthLargestValue(vector<vector<int> >& matrix, int k) {
     int m = matrix.size();
     int n = matrix[0].size();
     vector<int> v(m * n);
     int idx = 0;
     v[idx++] = matrix[0][0];
     for (int i = 1; i < m; ++i) {
       matrix[i][0] ^= matrix[i - 1][0];
       v[idx++] = matrix[i][0];
     }
     for (int j = 1; j < n; ++j) {
       matrix[0][j] ^= matrix[0][j - 1];
       v[idx++] = matrix[0][j];
     }
     for (int i = 1; i < m; ++i) {
       for (int j = 1; j < n; ++j) {
         matrix[i][j] ^= matrix[i - 1][j] ^ matrix[i][j - 1] ^ matrix[i - 1][j - 1];
         v[idx++] = matrix[i][j];
       }
     }

     return getKth(v, k);
   }

 private:
   int getKth(vector<int>& v, int k) {
     int sz = v.size();
     int l = 0;
     int r = sz - 1;
     int p = partition(v, l, r);
     while (p != sz - k) {
       if (p < sz - k) {
         l = p + 1;
       } else {
         r = p - 1;
       }
       p = partition(v, l, r);
     }
     return v[p];
   }

   int partition(vector<int>& vec, int left, int right) {
     if (left == right) {
       return left;
     }

     int v = vec[right];
     int i = left - 1;
     int j = right;
     for (;;) {
       while (vec[++i] < v);
       while (j > left && vec[--j] > v);
       if (i >= j) {
         break;
       }
       std::swap(vec[i], vec[j]);
     }
     std::swap(vec[i], vec[right]);
     return i;
   }
};
