#include <gtest/gtest.h>
#include "zigzag_conversion.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	string zigzag = solution_.convert(string("PAYPALISHIRING"), 3);
	EXPECT_EQ(zigzag, string("PAHNAPLSIIGYIR"));
}

TEST_F(SolutionTest, case2) {
	string zigzag = solution_.convert(string("ABC"), 2);
	EXPECT_EQ(zigzag, string("ACB"));
}

TEST_F(SolutionTest, case3) {
	string zigzag = solution_.convert(string("ABCD"), 2);
	EXPECT_EQ(zigzag, string("ACBD"));
}

TEST_F(SolutionTest, case4) {
	string zigzag = solution_.convert(string("ABCDE"), 4);
	EXPECT_EQ(zigzag, string("ABCED"));
}

TEST_F(SolutionTest, case5) {
	string zigzag = solution_.convert(string("AB"), 1);
	EXPECT_EQ(zigzag, string("AB"));
}

