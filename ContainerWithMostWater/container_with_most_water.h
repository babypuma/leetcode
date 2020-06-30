#include <vector>
#include <algorithm>
using std::vector;

#define min(a, b) (a < b ? a : b)

class Solution {
public:
    int maxArea(vector<int>& height) {
      int max_area = 0;
      std::pair<int, int> p(0, height.size() - 1); 
      while (p.first < p.second) {
        int area = (p.second - p.first) * min(height[p.first], height[p.second]);
        if (area > max_area) {
          max_area = area;
        }

        if (height[p.first] < height[p.second]) {
          ++p.first;
        } else if (height[p.first] > height[p.second]) {
          --p.second;
        } else {
          ++p.first;
          --p.second;
        }
      }

      return max_area;
    }
};
