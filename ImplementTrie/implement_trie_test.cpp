/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/07/11
 *
 * Source : https://leetcode.com/problems/implement-trie-prefix-tree/
 * Problem:	Implement Trie
 *
 */
#include <gtest/gtest.h>
#include "implement_trie.h"

#include <iostream>
using std::cout;
using std::endl;

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Trie trie;
};

TEST_F(SolutionTest, case1) {
	trie.insert("somestring");
	EXPECT_TRUE(trie.startsWith("somestring"));
	EXPECT_TRUE(trie.startsWith("so"));
	EXPECT_TRUE(trie.startsWith("somestr"));
	EXPECT_TRUE(trie.startsWith("somestring"));

	EXPECT_FALSE(trie.search("some"));
	EXPECT_FALSE(trie.search("somestr"));
	EXPECT_TRUE(trie.search("somestring"));
}

TEST_F(SolutionTest, case2) {
	trie.insert("abc");
	EXPECT_TRUE(trie.search("abc"));
	EXPECT_FALSE(trie.search("ab"));
	trie.insert("ab");
	EXPECT_TRUE(trie.search("ab"));
	trie.insert("ab");
	EXPECT_TRUE(trie.search("ab"));
}

