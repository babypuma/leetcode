#include <vector>
using std::vector;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
      vector<int> vec(nums.size() + 1, 0);
      for (vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it) {
        vec[*it] = 1;
      }
      for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == 0) {
          return i;
        }
      }
    }
};
