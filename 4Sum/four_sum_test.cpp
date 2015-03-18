#include <gtest/gtest.h>
#include "four_sum.h"

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
	int a[] = {1, 0, -1, 0, -2, 2};
	vector<int> vec(a, a + sizeof(a)/sizeof(int));
	vector<vector<int> > vvec;
	vvec = solution_.fourSum(vec, 0);

	EXPECT_EQ((int)vvec.size(), 3);
	int b[] = {-1,  0, 0, 1};
	vector<int> v1(b, b + sizeof(b)/sizeof(int));
	EXPECT_TRUE(find(vvec.begin(), vvec.end(), v1) != vvec.end());

	int c[] = {-2, -1, 1, 2};
	vector<int> v2(c, c + sizeof(c)/sizeof(int));
	EXPECT_TRUE(find(vvec.begin(), vvec.end(), v2) != vvec.end());

	int d[] = {-2,  0, 0, 2};
	vector<int> v3(d, d + sizeof(d)/sizeof(int));
	EXPECT_TRUE(find(vvec.begin(), vvec.end(), v3) != vvec.end());
}

TEST_F(SolutionTest, case2) {
	int a[] = {-3, -2, -1, 0, 0, 1, 2, 3};
	vector<int> vec(a, a + sizeof(a)/sizeof(int));
	vector<vector<int> > vvec;
	vvec = solution_.fourSum(vec, 0);

	EXPECT_EQ((int)vvec.size(), 8);
}

TEST_F(SolutionTest, case3) {
	int a[] = {1, -2, -5, -4, -3, 3, 3, 5};
	vector<int> vec(a, a + sizeof(a)/sizeof(int));
	vector<vector<int> > vvec;
	vvec = solution_.fourSum(vec, -11);

	EXPECT_EQ((int)vvec.size(), 1);
	int b[] = {-5, -4, -3, 1};
	vector<int> v1(b, b + sizeof(b)/sizeof(int));
	EXPECT_TRUE(find(vvec.begin(), vvec.end(), v1) != vvec.end());
}

