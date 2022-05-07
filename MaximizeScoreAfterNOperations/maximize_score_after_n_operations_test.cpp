/*
 * Author : Jimmy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2022/05/06
 *
 * Source : https://leetcode-cn.com/problems/maximize-score-after-n-operations/
 * Problem:	Maximize Score After N Operations
 *
 */
#include <gtest/gtest.h>
#include "maximize_score_after_n_operations.h"

TEST(Solution, case1) {
  Solution solution;
  int arr[] = {1,2,3,4,5,6};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(arr[0]));
	EXPECT_EQ(solution.maxScore(nums), 14);
}

TEST(Solution, case2) {
  Solution solution;
  int arr[] = {1,2};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(arr[0]));
	EXPECT_EQ(solution.maxScore(nums), 1);
}

TEST(Solution, case3) {
  Solution solution;
  int arr[] = {3,4,6,8};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(arr[0]));
	EXPECT_EQ(solution.maxScore(nums), 11);
}

TEST(Solution, case4) {
  Solution solution;
  int arr[] = {984916,312350,779975,165893,436389,592384,264617,136726,8893,587955,921403,891842};
  vector<int> nums(arr, arr + sizeof(arr)/sizeof(arr[0]));
	EXPECT_EQ(solution.maxScore(nums), 257);
}

