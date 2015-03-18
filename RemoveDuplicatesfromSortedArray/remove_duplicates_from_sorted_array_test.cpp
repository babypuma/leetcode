/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2014/10/27
 *
 * Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
 * Problem:	Remove Duplicates from Sorted Array
 *               
 */
#include <gtest/gtest.h>
#include "remove_duplicates_from_sorted_array.h"

using std::set;

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	int a[] = {1, 2, 2, 3, 4, 5};
	int length = solution_.removeDuplicates(a, sizeof(a)/sizeof(int));
	ASSERT_EQ(length, 5);

	int b[] = {1, 2, 3, 4, 5};
	ASSERT_EQ(length, (int)sizeof(b)/sizeof(int));
	for (int i = 0; i < length; i++) {
		EXPECT_EQ(a[i], b[i]);
	}
}

