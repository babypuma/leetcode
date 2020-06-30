#include <gtest/gtest.h>
#include "container_with_most_water.h"

using std::cout;
using std::endl;

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, longestPalindrome) {
  int test_data[] = {1,8,6,2,5,4,8,3,7};
  vector<int> vec;
  for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); ++i) {
    vec.push_back(test_data[i]);
  }
  EXPECT_EQ(solution_.maxArea(vec), 49);
}
