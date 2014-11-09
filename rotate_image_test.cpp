/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/09
 *
 * Source : https://oj.leetcode.com/problems/rotate-image/
 * Problem:	Rotate Image
 *
 */
#include <gtest/gtest.h>
#include "rotate_image.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	vector<vector<int> > vec2d;
	int a[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	for (size_t i = 0; i < sizeof(a)/sizeof(int[3]); i++) {
		vector<int> vec(a[i], a[i] + sizeof(a)/sizeof(int[3]));
		ASSERT_EQ(sizeof(a)/sizeof(int[3]), vec.size());
		vec2d.push_back(vec);
	}

	ASSERT_EQ(sizeof(a)/sizeof(int[3]), (int)vec2d.size());
	solution_.rotate(vec2d);
	int b[][3] = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
	for (size_t i = 0; i < sizeof(b)/sizeof(int[3]); i++) {
		for (size_t j = 0; j < sizeof(b[i])/sizeof(int); j++) {
			EXPECT_EQ(b[i][j], vec2d[i][j]);
		}
	}
}

TEST_F(SolutionTest, case2) {
	vector<vector<int> > vec2d;
	int a[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	for (size_t i = 0; i < sizeof(a)/sizeof(int[4]); i++) {
		vector<int> vec(a[i], a[i] + sizeof(a)/sizeof(int[4]));
		vec2d.push_back(vec);
	}

	ASSERT_EQ(sizeof(a)/sizeof(int[4]), vec2d.size());
	solution_.rotate(vec2d);
	int b[][4] = {{13, 9, 5, 1}, {14, 10, 6, 2}, {15, 11, 7, 3}, {16, 12, 8, 4}};
	for (size_t i = 0; i < sizeof(b)/sizeof(int[4]); i++) {
		for (size_t j = 0; j < sizeof(b[i])/sizeof(int); j++) {
			EXPECT_EQ(b[i][j], vec2d[i][j]);
		}
	}
}

