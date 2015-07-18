/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 *
 * Source : https://leetcode.com/problems/product-of-array-except-self/
 * Problem:	Product of Array Except Self
 *
 */
#include <gtest/gtest.h>
#include "product_of_array_except_helf.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	int a[] = {1, 2, 3, 4};
	int b[] = {24, 12, 8, 6};
	vector<int> vec(a, a + sizeof(a) / sizeof(int));
	vector<int> v = solution_.productExceptSelf(vec);
	for (size_t i = 0; i < vec.size(); i++) {
		EXPECT_EQ(v[i], b[i]);
	}
}

