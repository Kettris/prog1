#include "gtest/gtest.h"
#include "long_number.hpp"
#include <stdexcept>

using biv::LongNumber;

// Проверка на создание LongNumber из строки
TEST(LongNumberTest, ConstructorFromString) {
    LongNumber num("12345");
    ASSERT_EQ(num.get_digits_number(), 5);
    ASSERT_EQ(num.get_rank_number(0), 5);
    ASSERT_EQ(num.get_rank_number(4), 1);
    ASSERT_FALSE(num.is_negative());

    LongNumber negativeNum("-54321");
    ASSERT_EQ(negativeNum.get_digits_number(), 5);
    ASSERT_EQ(negativeNum.get_rank_number(0), 1);
    ASSERT_EQ(negativeNum.get_rank_number(4), 5);
    ASSERT_TRUE(negativeNum.is_negative());

    LongNumber zeroNum("0");
    ASSERT_EQ(zeroNum.get_digits_number(), 1);
    ASSERT_EQ(zeroNum.get_rank_number(0), 0);
    ASSERT_FALSE(zeroNum.is_negative());

    ASSERT_THROW(LongNumber invalidNum("123a"), std::invalid_argument);
    ASSERT_THROW(LongNumber emptyNum(""), std::invalid_argument);
}

//копирующий конструктор
TEST(LongNumberTest, CopyConstructor) {
    LongNumber num("98765");
    LongNumber copyNum(num);
    ASSERT_EQ(copyNum.get_digits_number(), 5);
    ASSERT_EQ(copyNum.get_rank_number(0), 5);
    ASSERT_EQ(copyNum.get_rank_number(4), 9);
    ASSERT_FALSE(copyNum.is_negative());
}

// присваивания
TEST(LongNumberTest, AssignmentOperator) {
    LongNumber num;
    num = "556677";
    ASSERT_EQ(num.get_digits_number(), 6);
    ASSERT_EQ(num.get_rank_number(0), 7);
    ASSERT_EQ(num.get_rank_number(5), 5);
    ASSERT_FALSE(num.is_negative());
}

// равенства
TEST(LongNumberTest, EqualityOperator) {
    LongNumber num1("123");
    LongNumber num2("123");
    LongNumber num3("321");
    ASSERT_TRUE(num1 == num2);
    ASSERT_FALSE(num1 == num3);
}

//неравенства
TEST(LongNumberTest, InequalityOperator) {
    LongNumber num1("123");
    LongNumber num2("321");
    ASSERT_TRUE(num1 != num2);
}

// сложения
TEST(LongNumberTest, AdditionOperator) {
    LongNumber num1("123");
    LongNumber num2("456");
    LongNumber sum = num1 + num2;
    ASSERT_EQ(sum, LongNumber("579"));

    LongNumber num3("-123");
    LongNumber sumNegative = num1 + num3;
    ASSERT_EQ(sumNegative, LongNumber("0"));
}


TEST(LongNumberTest, LessThanOperator) {
    LongNumber num1("123");
    LongNumber num2("321");
    ASSERT_TRUE(num1 < num2);
    ASSERT_FALSE(num2 < num1);
}


TEST(LongNumberTest, GreaterThanOperator) {
    LongNumber num1("321");
    LongNumber num2("123");
    ASSERT_TRUE(num1 > num2);
    ASSERT_FALSE(num2 > num1);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
