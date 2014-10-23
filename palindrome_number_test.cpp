#include <gtest/gtest.h>
#include "palindrome_number.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	EXPECT_TRUE(solution_.isPalindrome(0));
}

TEST_F(SolutionTest, case2) {
	EXPECT_FALSE(solution_.isPalindrome(-1));
}

TEST_F(SolutionTest, case3) {
	EXPECT_TRUE(solution_.isPalindrome(123454321));
}

TEST_F(SolutionTest, case4) {
	EXPECT_TRUE(solution_.isPalindrome(12344321));
}

TEST_F(SolutionTest, case5) {
	EXPECT_TRUE(solution_.isPalindrome(9));
}

