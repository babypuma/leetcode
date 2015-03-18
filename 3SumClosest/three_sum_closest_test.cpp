#include <gtest/gtest.h>
#include "three_sum_closest.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	int a[] = {-1, 1, 2, -4};
	vector<int> vec(a, a + sizeof(a)/sizeof(int));
	EXPECT_EQ(solution_.threeSumClosest(vec, 1), 2);
}

TEST_F(SolutionTest, case2) {
	int a[] = {0, 1, 2};
	vector<int> vec(a, a + sizeof(a)/sizeof(int));
	EXPECT_EQ(solution_.threeSumClosest(vec, 3), 3);
}

TEST_F(SolutionTest, case3) {
	int a[] = {0,-4, 1,-5};
	vector<int> vec(a, a + sizeof(a)/sizeof(int));
	EXPECT_EQ(solution_.threeSumClosest(vec, 0), -3);
}

