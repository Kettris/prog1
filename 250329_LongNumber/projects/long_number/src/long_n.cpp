#include "long_number.hpp"
#include <algorithm>
#include <stdexcept> // Для исключений
#include <cctype> // Для isdigit

LongNumber::LongNumber() : digits({0}), negative(false) {}

LongNumber::LongNumber(long long number) {
    if (number < 0) {
        negative = true;
        number = -number;
    } else {
        negative = false;
    }

    if (number == 0) {
        digits.push_back(0);
        return;
    }

    while (number > 0) {
        digits.push_back(number % 10);
        number /= 10;
    }

    std::reverse(digits.begin(), digits.end());
}

LongNumber::LongNumber(const std::string& number) {
    if (number.empty()) {
        throw std::invalid_argument("Строка не должна быть пустой.");
    }

    negative = (number[0] == '-');
    size_t start_index = negative ? 1 : 0;

    if (start_index == number.length()) {
        throw std::invalid_argument("Строка содержит только знак минус.");
    }


    for (size_t i = start_index; i < number.length(); ++i) {
        if (!isdigit(number[i])) {
            throw std::invalid_argument("Строка должна содержать только цифры (и, возможно, знак минус в начале).");
        }
        digits.push_back(number[i] - '0');
    }
    remove_leading_zeros();
    if (digits.empty()) {
        digits.push_back(0);
        negative = false;
    }
}

LongNumber::LongNumber(const LongNumber& other) : digits(other.digits), negative(other.negative) {}

LongNumber& LongNumber::operator=(const LongNumber& other) {
    if (this != &other) {
        digits = other.digits;
        negative = other.negative;
    }
    return *this;
}

LongNumber LongNumber::operator + (const LongNumber& x) const {
   // Реализация сложения (опущено для краткости, будет ниже)
   // Учитывайте знаки, переполнение и т.д.
    LongNumber result;
    return result;
}

LongNumber LongNumber::operator - (const LongNumber& x) const {
   // Реализация вычитания (опущено для краткости)
    LongNumber result;
    return result;
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
    // Реализация умножения
    LongNumber result;
    return result;
}

LongNumber LongNumber::operator / (const LongNumber& x) const {
    // Реализация деления
    LongNumber result;
    return result;
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
    // Реализация взятия остатка
    LongNumber result;
    return result;
}

bool LongNumber::operator == (const LongNumber& x) const {
    return (negative == x.negative) && (digits == x.digits);
}

 bool LongNumber::operator != (const LongNumber& x) const {
    return !(*this == x);
}

bool LongNumber::operator < (const LongNumber& x) const {
    if (negative && !x.negative) return true;
    if (!negative && x.negative) return false;

    if (!negative) { // Оба положительные
        if (digits.size() < x.digits.size()) return true;
        if (digits.size() > x.digits.size()) return false;
        return digits < x.digits;
    } else { // Оба отрицательные
        if (digits.size() > x.digits.size()) return true;
        if (digits.size() < x.digits.size()) return false;
        return digits > x.digits; // Сравниваем как положительные, но наоборот
    }
}

bool LongNumber::operator > (const LongNumber& x) const {
    return x < *this;
}

bool LongNumber::operator <= (const LongNumber& x) const {
    return !(x < *this);
}

bool LongNumber::operator >= (const LongNumber& x) const {
    return !(*this < x);
}

int LongNumber::get_digits_number() const noexcept {
    return digits.size();
}

int LongNumber::get_rank_number(int rank) const {
    if (rank < 0 || rank >= digits.size()) {
        return 0; // Или выбросить исключение, в зависимости от требований
    }
    return digits[digits.size() - 1 - rank];
}

bool LongNumber::is_negative() const noexcept {
    return negative;
}

int LongNumber::get_length(const char* const str) const noexcept {
    if (!str) return 0;
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void LongNumber::remove_leading_zeros() {
    while (digits.size() > 1 && digits.front() == 0) {
        digits.erase(digits.begin());
    }
}

namespace biv {
std::ostream& operator << (std::ostream &os, const LongNumber& x) {
    if (x.negative) {
        os << "-";
    }
    for (int digit : x.digits) {
        os << digit;
    }
    return os;
}
}