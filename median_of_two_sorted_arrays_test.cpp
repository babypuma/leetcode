#include <gtest/gtest.h>
#include "median_of_two_sorted_arrays.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	int A[] = {1, 3, 5, 7, 9};
	int B[] = {2, 4, 6, 8, 10};
	EXPECT_DOUBLE_EQ(solution_.findMedianSortedArrays(A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int)), 5.5);
}

TEST_F(SolutionTest, case2) {
	int A[] = {1, 3, 5, 7, 9};
	int B[] = {2, 4, 6, 8, 10};
	EXPECT_DOUBLE_EQ(solution_.findMedianSortedArrays(A, 0, B, sizeof(B)/sizeof(int)), 6.0);
}

TEST_F(SolutionTest, case3) {
	int A[] = {1, 3, 5, 7, 9};
	int B[] = {2, 4, 6, 8, 10};
	EXPECT_DOUBLE_EQ(solution_.findMedianSortedArrays(A, sizeof(A)/sizeof(int), B, 0), 5.0);
}

TEST_F(SolutionTest, case4) {
	int A[] = {1, 3, 5};
	int B[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	EXPECT_DOUBLE_EQ(solution_.findMedianSortedArrays(A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int)), 8.0);
}

TEST_F(SolutionTest, case5) {
	int A[] = {1, 3, 5};
	int B[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22};
	EXPECT_DOUBLE_EQ(solution_.findMedianSortedArrays(A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int)), 9.0);
}

TEST_F(SolutionTest, case6) {
	int A[] = {1, 3, 5, 7, 9};
	int B[] = {2, 4, 6, 8, 10, 12};
	EXPECT_DOUBLE_EQ(solution_.findMedianSortedArrays(A, 0, B, sizeof(B)/sizeof(int)), 7.0);
}

TEST_F(SolutionTest, case7) {
	int A[] = {1, 3, 5, 7, 9};
	int B[] = {2, 4, 6, 8, 10, 12};
	EXPECT_DOUBLE_EQ(solution_.findMedianSortedArrays(A, 0, B, 2), 3.0);
}

TEST_F(SolutionTest, case8) {
	int A[] = {2, 2, 2, 2};
	int B[] = {2, 2, 2};
	EXPECT_DOUBLE_EQ(solution_.findMedianSortedArrays(A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int)), 2.0);
}

TEST_F(SolutionTest, case9) {
	int A[] = {3};
	int B[] = {1, 2};
	EXPECT_DOUBLE_EQ(solution_.findMedianSortedArrays(A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int)), 2.0);
}

