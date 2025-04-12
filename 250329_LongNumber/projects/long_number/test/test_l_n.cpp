#include "gtest/gtest.h"
#include "long_number.hpp"

TEST(LongNumberTest, ConstructorFromString) {
    LongNumber num("12345");
    ASSERT_EQ(num.get_digits_number(), 5);
    ASSERT_EQ(num.get_rank_number(0), 5);
    ASSERT_EQ(num.get_rank_number(4), 1);

    LongNumber negative_num("-9876");
    ASSERT_TRUE(negative_num.is_negative());
    ASSERT_EQ(negative_num.get_digits_number(), 4);
    ASSERT_EQ(negative_num.get_rank_number(0), 6);
}

TEST(LongNumberTest, ConstructorFromLongLong) {
    LongNumber num(12345LL);
    ASSERT_EQ(num.get_digits_number(), 5);
    ASSERT_EQ(num.get_rank_number(0), 5);
    ASSERT_EQ(num.get_rank_number(4), 1);

    LongNumber negative_num(-9876LL);
    ASSERT_TRUE(negative_num.is_negative());
    ASSERT_EQ(negative_num.get_digits_number(), 4);
    ASSERT_EQ(negative_num.get_rank_number(0), 6);
}

TEST(LongNumberTest, Addition) {
    LongNumber num1("123");
    LongNumber num2("456");
    LongNumber sum = num1 + num2;
    ASSERT_EQ(biv::operator <<(std::cout, sum).str(), "579");
}

TEST(LongNumberTest, Subtraction) {
    LongNumber num1("456");
    LongNumber num2("123");
    LongNumber diff = num1 - num2;
    ASSERT_EQ(biv::operator <<(std::cout, diff).str(), "333");
}

TEST(LongNumberTest, Multiplication) {
    LongNumber num1("12");
    LongNumber num2("10");
    LongNumber product = num1 * num2;
    ASSERT_EQ(biv::operator <<(std::cout, product).str(), "120");
}

TEST(LongNumberTest, Division) {
    LongNumber num1("144");
    LongNumber num2("12");
    LongNumber quotient = num1 / num2;
    ASSERT_EQ(biv::operator <<(std::cout, quotient).str(), "12");
}

TEST(LongNumberTest, Modulo) {
    LongNumber num1("145");
    LongNumber num2("12");
    LongNumber remainder = num1 % num2;
    ASSERT_EQ(biv::operator <<(std::cout, remainder).str(), "1");
}

TEST(LongNumberTest, Comparison) {
    LongNumber num1("123");
    LongNumber num2("456");
    LongNumber num3("123");

    ASSERT_TRUE(num1 < num2);
    ASSERT_FALSE(num2 < num1);
    ASSERT_FALSE(num1 < num3);

    ASSERT_TRUE(num2 > num1);
    ASSERT_FALSE(num1 > num2);
    ASSERT_FALSE(num1 > num3);

    ASSERT_TRUE(num1 <= num3);
    ASSERT_TRUE(num1 <= num2);
    ASSERT_FALSE(num2 <= num1);

    ASSERT_TRUE(num1 >= num3);
    ASSERT_TRUE(num2 >= num1);
    ASSERT_FALSE(num1 >= num2);

    ASSERT_TRUE(num1 == num3);
    ASSERT_FALSE(num1 == num2);

    ASSERT_TRUE(num1 != num2);
    ASSERT_FALSE(num1 != num3);
}