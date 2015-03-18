#include <gtest/gtest.h>
#include "remove_element.h"

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
	int length = solution_.removeElement(a, sizeof(a)/sizeof(int), 2);

	int b[] = {1, 3, 4, 5};
	ASSERT_EQ((int)sizeof(b)/sizeof(int), length);
	for (size_t i = 0; i < sizeof(b)/sizeof(int); i++) {
		EXPECT_EQ(a[i], b[i]);
	}
}

TEST_F(SolutionTest, case2) {
	int a[] = {1, 2, 2, 3, 4, 5};
	int length = solution_.removeElement(a, sizeof(a)/sizeof(int), 5);

	int b[] = {1, 2, 2, 3, 4};
	ASSERT_EQ((int)sizeof(b)/sizeof(int), length);
	for (size_t i = 0; i < sizeof(b)/sizeof(int); i++) {
		EXPECT_EQ(a[i], b[i]);
	}

}

