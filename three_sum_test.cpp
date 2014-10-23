#include <gtest/gtest.h>
#include <set>
#include "three_sum.h"

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
	int a[] = {-1, 0, 1, 2, -1, -4};
	vector<int> vec(a, a + sizeof(a)/sizeof(int));
	vector<vector<int> > vvec;
	vvec = solution_.threeSum(vec);

	set<vector<int> > res;
	int b[] = {-1, 0, 1};
	vector<int> v1(b, b + sizeof(b)/sizeof(int));
	res.insert(v1);
	int c[] = {-1, -1, 2};
	vector<int> v2(c, c + sizeof(c)/sizeof(int));
	res.insert(v2);
	for (vector<vector<int> >::iterator it = vvec.begin(); it != vvec.end(); it++) {
		EXPECT_TRUE(res.find(*it) != res.end());
	}
}


TEST_F(SolutionTest, case2) {
	int a[] = {3,-9,3,9,-6,-1,-2,8,6,-7,-14,-15,-7,5,2,-7,-4,2,-12,-7,-1,-2,1,-15,-13,-4,0,-9,-11,7,4,7,13,14,-7,-8,-1,-2,7,-10,-2,1,-10,6,-9,-1,14,2,-13,9,10,-7,-8,-4,-14,-5,-1,1,1,4,-15,13,-12,13,12,-11,12,-12,2,-3,-7,-14,13,-9,7,-11,5,-1,-2,-1,-7,-7,0,-7,-4,1,3,3,9,11,14,10,1,-13,8,-9,13,-2,-6,1,10,-5,-6,0,1,8,4,13,14,9,-2,-15,-13};
	vector<int> vec(a, a + sizeof(a)/sizeof(int));
	vector<vector<int> > vvec = solution_.threeSum(vec);
	for (vector<vector<int> >::iterator it = vvec.begin(); it != vvec.end(); it++) {
		printf("<%d, %d, %d>\n", (*it)[0], (*it)[1], (*it)[2]);
	}
}

