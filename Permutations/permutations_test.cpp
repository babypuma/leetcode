/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/11/06
 *
 * Source : https://oj.leetcode.com/problems/permutations/
 * Problem:	Permutations
 *
 */
#include <gtest/gtest.h>
#include "permutations.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	int a[] = {1, 2, 3};
	vector<int> vec(a, a + sizeof(a)/sizeof(int));

	vector<vector<int> > vec2d = solution_.permute(vec);
	int b[][3] = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
	for (size_t i = 0; i < sizeof(b)/sizeof(int[3]); i++) {
		for (size_t j = 0; j < sizeof(b[i])/sizeof(int); j++) {
			EXPECT_EQ(vec2d[i][j], b[i][j]);
		}
	}
}

