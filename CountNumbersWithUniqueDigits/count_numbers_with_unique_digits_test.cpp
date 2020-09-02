/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2020/09/01
 *
 * Source : https://leetcode.com/problems/count-numbers-with-unique-digits/
 * Problem:	Count Numbers with Unique Digits
 *
 */
#include <gtest/gtest.h>
#include "count_numbers_with_unique_digits.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, countNumbersWithUniqueDigits) {
  Solution solution;
  EXPECT_EQ(solution.countNumbersWithUniqueDigits(2), 91);
  EXPECT_EQ(solution.countNumbersWithUniqueDigits(0), 1);
}

