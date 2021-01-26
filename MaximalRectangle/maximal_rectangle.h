/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2021/01/26
 *
 * Source : https://leetcode-cn.com/problems/maximal-rectangle/
 * Problem:	Maximal Rectangle
 *
 */
#include <vector>
#include <stack>
using std::vector;
using std::stack;

class Solution {
 public:
   int maximalRectangle(vector<vector<char> >& matrix) {
     if (matrix.empty() || matrix[0].empty()) {
       return 0;
     }
     int m = matrix.size();
     int n = matrix[0].size();
     vector<vector<int> > m2(m, vector<int>(n, 0));
     for (int i = 0; i < m; ++i) {
       for (int j = 0; j < n; ++j) {
         m2[i][j] = (matrix[i][j] == '0') ? 0 : (j > 0 ? m2[i][j - 1] + 1 : 1);
       }
     }

     int ans = 0;
     stack<int> st;
     vector<int> forward(m, 0);
     vector<int> backward(m, 0);
     for (int j = 0; j < n; ++j) {
       stack<int>().swap(st);
       for (int i = 0; i < m; ++i) {
         while (!st.empty() && m2[st.top()][j] >= m2[i][j]) {
           st.pop();
         }
         forward[i] = st.empty() ? -1 : st.top();
         st.push(i);
       }
       stack<int>().swap(st);
       for (int i = m - 1; i >= 0; --i) {
         while (!st.empty() && m2[st.top()][j] >= m2[i][j]) {
           st.pop();
         }
         backward[i] = st.empty() ? m : st.top();
         st.push(i);
       }
       int height = 0;
       for (int i = 0; i < m; ++i) {
         height = backward[i] - forward[i] - 1;
         ans = std::max(ans, height * m2[i][j]);
       }
     }

     return ans;
   }
};
