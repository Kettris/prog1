#include <gtest/gtest.h>
#include "vector.hpp"

using biv::Vector;

TEST(VectorTest, PushBack) {
	Vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	EXPECT_EQ(vec.get_size(), 3);
	EXPECT_TRUE(vec.has_item(2));
}

TEST(VectorTest, RemoveFirst) {
	Vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	EXPECT_TRUE(vec.remove_first(2));
	EXPECT_EQ(vec.get_size(), 2);
	EXPECT_FALSE(vec.has_item(2));
}

TEST(VectorTest, Insert) {
	Vector<int> vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.insert(1, 2);
	EXPECT_EQ(vec.get_size(), 3);
	EXPECT_TRUE(vec.has_item(2));
}

TEST(VectorTest, Print) {
	Vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.print(); // Ожидаемый вывод: 1 2 3
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
