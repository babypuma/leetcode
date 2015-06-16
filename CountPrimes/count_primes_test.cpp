/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 *
 * Source : https://leetcode.com/problems/house-robber/
 * Problem:	Count Primes
 *
 */
#include <gtest/gtest.h>
#include "count_primes.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
	EXPECT_EQ(solution_.countPrimes(2), 0);
	EXPECT_EQ(solution_.countPrimes(10), 4);
	EXPECT_EQ(solution_.countPrimes(20), 8);
	EXPECT_EQ(solution_.countPrimes(100), 25);
}

TEST_F(SolutionTest, case2) {
	EXPECT_EQ(solution_.countPrimes(0), 0);
	EXPECT_EQ(solution_.countPrimes(49979), 5130);
}

