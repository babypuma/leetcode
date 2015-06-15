/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 *
 * Source : https://leetcode.com/problems/rotate-array/
 * Problem:	Rotate Array
 *
 */
#include <gtest/gtest.h>
#include "rotate_array.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	int b[] = {5, 6, 7, 1, 2, 3, 4};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	solution_.rotate(vec, 3);
	for (size_t i = 0; i < sizeof(b) / sizeof(int); i++) {
		EXPECT_EQ(vec[i], b[i]);
	}
}

TEST_F(SolutionTest, case2) {
	int a[] = {1};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	solution_.rotate(vec, 3);
	for (size_t i = 0; i < sizeof(a) / sizeof(int); i++) {
		EXPECT_EQ(vec[i], a[i]);
	}
}

TEST_F(SolutionTest, case3) {
	int a[] = {1, 2};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	solution_.rotate(vec, 2);
	for (size_t i = 0; i < sizeof(a) / sizeof(int); i++) {
		EXPECT_EQ(vec[i], a[i]);
	}
}

TEST_F(SolutionTest, case4) {
	int a[] = {1, 2};
	int b[] = {2, 1};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	solution_.rotate(vec, 3);
	for (size_t i = 0; i < sizeof(b) / sizeof(int); i++) {
		EXPECT_EQ(vec[i], b[i]);
	}
}

