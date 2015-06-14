#include <gtest/gtest.h>
#include "find_peak_element.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	int a[4] = {1, 2, 3, 1};
	vector<int> vec(a, a + 4);
	EXPECT_EQ(solution_.findPeakElement(vec), 2);
}

TEST_F(SolutionTest, case2) {
	int a[4] = {1, 2, 3, 4};
	vector<int> vec(a, a + 4);
	EXPECT_EQ(solution_.findPeakElement(vec), 3);
}

TEST_F(SolutionTest, case3) {
	int a[4] = {5, 2, 3, 4};
	vector<int> vec(a, a + 4);
	EXPECT_EQ(solution_.findPeakElement(vec), 0);
}

TEST_F(SolutionTest, case4) {
	vector<int> vec;
	vec.push_back(1);
	EXPECT_EQ(solution_.findPeakElement(vec), 0);
}

