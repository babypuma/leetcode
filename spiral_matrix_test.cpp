/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/16
 *
 * Source : https://oj.leetcode.com/problems/spiral-matrix/
 * Problem:	Spiral Matrix
 *
 */
#include <gtest/gtest.h>
#include <set>
#include "spiral_matrix.h"

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
	int a[][2] = {{1, 2}, {3, 4}};
	for (size_t i = 0; i < sizeof(a)/sizeof(int[2]); i++) {
		vector<int> vec(a[i], a[i] + sizeof(a[i])/sizeof(int));
		vec2d.push_back(vec);
	}
	vector<int> v = solution_.spiralOrder(vec2d);

	int b[] = {1, 2, 4, 3};
	ASSERT_EQ(sizeof(b)/sizeof(int), v.size());
	for (size_t i = 0; i < v.size(); i++) {
		EXPECT_EQ(b[i], v[i]);
	}
}

TEST_F(SolutionTest, case2) {
	vector<vector<int> > vec2d;
	int a[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	for (size_t i = 0; i < sizeof(a)/sizeof(int[3]); i++) {
		vector<int> vec(a[i], a[i] + sizeof(a[i])/sizeof(int));
		vec2d.push_back(vec);
	}
	vector<int> v = solution_.spiralOrder(vec2d);

	int b[] = {1, 2, 3, 6, 9, 8, 7, 4, 5};
	ASSERT_EQ(sizeof(b)/sizeof(int), v.size());
	for (size_t i = 0; i < v.size(); i++) {
		EXPECT_EQ(b[i], v[i]);
	}
}

TEST_F(SolutionTest, case3) {
	vector<vector<int> > vec2d;
	int a[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	for (size_t i = 0; i < sizeof(a)/sizeof(int[4]); i++) {
		vector<int> vec(a[i], a[i] + sizeof(a[i])/sizeof(int));
		vec2d.push_back(vec);
	}
	vector<int> v = solution_.spiralOrder(vec2d);

	int b[] = {1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10};
	ASSERT_EQ(sizeof(b)/sizeof(int), v.size());
	for (size_t i = 0; i < v.size(); i++) {
		EXPECT_EQ(b[i], v[i]);
	}
}

TEST_F(SolutionTest, case4) {
	vector<vector<int> > vec2d;
	int a[][3] = {{2, 5, 8}, {4, 0, -1}};
	for (size_t i = 0; i < sizeof(a)/sizeof(int[3]); i++) {
		vector<int> vec(a[i], a[i] + sizeof(a[i])/sizeof(int));
		vec2d.push_back(vec);
	}
	vector<int> v = solution_.spiralOrder(vec2d);

	int b[] = {2, 5, 8, -1, 0, 4};
	ASSERT_EQ(sizeof(b)/sizeof(int), v.size());
	for (size_t i = 0; i < v.size(); i++) {
		EXPECT_EQ(b[i], v[i]);
	}
}

TEST_F(SolutionTest, case5) {
	vector<vector<int> > vec2d;
	vector<int> vec(1, 1);
	vec2d.push_back(vec);
	vector<int> v = solution_.spiralOrder(vec2d);
	ASSERT_EQ(1, (int)v.size());
	EXPECT_EQ(1, v[0]);
}

TEST_F(SolutionTest, case6) {
	vector<vector<int> > vec2d;
	vector<int> vec(1, 1);
	vec2d.push_back(vec);
	vector<int> v = solution_.spiralOrder(vec2d);
	ASSERT_EQ(1, (int)v.size());
	EXPECT_EQ(1, v[0]);
}

TEST_F(SolutionTest, case7) {
	vector<vector<int> > vec2d;
	int a[][3] = {{2, 3, 4}, {5, 6, 7}, {8, 9, 10}, {11, 12, 13}};
	for (size_t i = 0; i < sizeof(a)/sizeof(int[3]); i++) {
		vector<int> vec(a[i], a[i] + sizeof(a[i])/sizeof(int));
		vec2d.push_back(vec);
	}
	vector<int> v = solution_.spiralOrder(vec2d);

	int b[] = {2, 3, 4, 7, 10, 13, 12, 11, 8, 5, 6, 9};
	ASSERT_EQ(sizeof(b)/sizeof(int), v.size());
	for (size_t i = 0; i < v.size(); i++) {
		EXPECT_EQ(b[i], v[i]);
	}
}

