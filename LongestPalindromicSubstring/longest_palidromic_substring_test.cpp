#include <gtest/gtest.h>
#include "longest_palidromic_substring.h"

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
  struct TestData {
    const char* str;
    const char* sub_str;
  };
  TestData test_data[] = {
    // pattern 1
    {"abcba", "abcba"},
    {"ababc", "aba"},
    {"bbcba", "bcb"},
    {"abcda", "a"},
    // pattern 2
    {"abba", "abba"},
    {"aaba", "aba"},
    {"abbb", "bbb"},
    {"abbc", "bb"},
  };

  for (size_t i = 0;
       i < sizeof(test_data)/sizeof(test_data[0]);
       ++i) {
    string result = solution_.longestPalindrome(test_data[i].str);
    EXPECT_STREQ(result.c_str(), test_data[i].sub_str);
  }
}
