#ifndef LONG_NUMBER_HPP
#define LONG_NUMBER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class LongNumber {
public:
    LongNumber();
    LongNumber(const std::string& number);
    LongNumber(long long number);
    LongNumber(const LongNumber& other);
    LongNumber& operator=(const LongNumber& other);
    ~LongNumber() = default;

    LongNumber operator + (const LongNumber& x) const;
    LongNumber operator - (const LongNumber& x) const;
    LongNumber operator * (const LongNumber& x) const;
    LongNumber operator / (const LongNumber& x) const;
    LongNumber operator % (const LongNumber& x) const;

    bool operator == (const LongNumber& x) const;
    bool operator != (const LongNumber& x) const;
    bool operator < (const LongNumber& x) const;
    bool operator > (const LongNumber& x) const;
    bool operator <= (const LongNumber& x) const;
    bool operator >= (const LongNumber& x) const;

    int get_digits_number() const noexcept;
    int get_rank_number(int rank) const;
    bool is_negative() const noexcept;

private:
    std::vector<int> digits;
    bool negative;

    int get_length(const char* const str) const noexcept;
    void remove_leading_zeros();

friend std::ostream& biv::operator << (std::ostream &os, const LongNumber& x);
};

namespace biv {
std::ostream& operator << (std::ostream &os, const LongNumber& x);
}

#endif