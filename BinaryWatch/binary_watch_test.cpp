#include <gtest/gtest.h>
#include <iostream>
#include "binary_watch.h"

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
        }
        virtual void TearDown() {
        }

        Solution solution_;
};

TEST_F(SolutionTest, case1) {
  vector<string> vec = solution_.readBinaryWatch(1);
	EXPECT_EQ(vec.size(), 10);
  vec = solution_.readBinaryWatch(2);
	EXPECT_EQ(vec.size(), 44);
}

