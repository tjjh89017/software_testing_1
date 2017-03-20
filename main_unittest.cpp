#include "gtest/gtest.h"
#include "main.hpp"


TEST(triangle_type_test, BoundryValue) {
	EXPECT_EQ(ISOSCELES, triangle_type(100, 100, 1));
	EXPECT_EQ(ISOSCELES, triangle_type(100, 100, 2));
	EXPECT_EQ(EQUILATERAL, triangle_type(100, 100, 100));
	EXPECT_EQ(ISOSCELES, triangle_type(100, 100, 199));
	EXPECT_EQ(NOT_TRIANGLE, triangle_type(100, 100, 200));

	EXPECT_EQ(ISOSCELES, triangle_type(100, 1, 100));
	EXPECT_EQ(ISOSCELES, triangle_type(100, 2, 100));
	EXPECT_EQ(ISOSCELES, triangle_type(100, 199, 100));
	EXPECT_EQ(NOT_TRIANGLE, triangle_type(100, 200, 100));

	EXPECT_EQ(ISOSCELES, triangle_type(1, 100, 100));
	EXPECT_EQ(ISOSCELES, triangle_type(2, 100, 100));
	EXPECT_EQ(ISOSCELES, triangle_type(199, 100, 100));
	EXPECT_EQ(NOT_TRIANGLE, triangle_type(200, 100, 100));
}

TEST(triangle_type_test, EquivalenceClass) {
	
	EXPECT_EQ(EQUILATERAL, triangle_type(5, 5, 5));

	EXPECT_EQ(INVAILD, triangle_type(-1, 5, 5));
	EXPECT_EQ(INVAILD, triangle_type(5, -1, 5));
	EXPECT_EQ(INVAILD, triangle_type(5, 5, -1));

	EXPECT_EQ(INVAILD, triangle_type(201, 5, 5));
	EXPECT_EQ(INVAILD, triangle_type(5, 201, 5));
	EXPECT_EQ(INVAILD, triangle_type(5, 5, 201));
}

TEST(triangle_type_test, EdgeTesting) {
	EXPECT_EQ(INVAILD, triangle_type(0, 5, 5));
	EXPECT_NE(INVAILD, triangle_type(1, 5, 5));
	EXPECT_NE(INVAILD, triangle_type(2, 5, 5));
	EXPECT_NE(INVAILD, triangle_type(199, 5, 5));
	EXPECT_NE(INVAILD, triangle_type(200, 5, 5));
	EXPECT_EQ(INVAILD, triangle_type(201, 5, 5));
}
