#include <gtest/gtest.h>
#include "letter_combinations_of_a_phone_number_ii.h"

using std::set;

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case2) {
	vector<string> vec;
	vec = solution_.letterCombinations(string("23"));
	EXPECT_EQ((int)vec.size(), 9);

	char *chars[] = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
	for (size_t i = 0; i < sizeof(chars)/sizeof(char *); i++) {
		EXPECT_TRUE(find(vec.begin(), vec.end(), string(chars[i])) != vec.end());
	}
}

