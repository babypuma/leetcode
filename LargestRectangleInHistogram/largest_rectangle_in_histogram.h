/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/10/27
 *
 * Source : https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
 * Problem:	Largest Rectangle in Histogram
 *
 */
#include <vector>
#include <stack>
using std::vector;
using std::stack;

class Solution {
 public:
   int largestRectangleArea(vector<int>& heights) {
     int n = heights.size();
     vector<int> left(n);
     vector<int> right(n, n);
     stack<int> st;
     for (int i = 0; i < n; ++i) {
       while (!st.empty() && heights[st.top()] >= heights[i]) {
         right[st.top()] = i;
         st.pop();
       }
       left[i] = st.empty() ? -1 : st.top();
       st.push(i);
     }

     int area = 0;
     for (int i = 0; i < n; ++i) {
       area = std::max(area, (right[i] - left[i] - 1) * heights[i]);
     }
     return area;
   }
};
