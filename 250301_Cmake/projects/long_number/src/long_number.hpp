#pragma once
#include <iostream>

namespace biv {

	class LongNumber {
	private:
    	int* numbers; // хранит цифры
    	int length;   // длина числа
    	int sign;     // знак числа: 1 для положительного, -1 для отрицательного

	public:
    	LongNumber();
    	LongNumber(const char* const str);
    	LongNumber(const LongNumber& x);
    	LongNumber(LongNumber&& x);
    	~LongNumber();

    	LongNumber& operator=(const char* const str);
    	LongNumber& operator=(const LongNumber& x);
    	LongNumber& operator=(LongNumber&& x);

		bool operator==(const LongNumber& x) const;
		bool operator!=(const LongNumber& x) const;
		bool operator>(const LongNumber& x) const;
		bool operator<(const LongNumber& x) const;
		bool operator>=(const LongNumber& x) const;

		LongNumber operator + (const LongNumber& x) const;
		LongNumber operator - (const LongNumber& x) const;
		LongNumber operator * (const LongNumber& x) const;
		LongNumber operator / (const LongNumber& x) const;
		LongNumber operator % (const LongNumber& x) const;

		int get_digits_number() const noexcept;
		int get_rank_number(const int rank) const; //int get_rank_number(int rank) const;
		bool is_negative() const noexcept;

		friend std::ostream& operator<<(std::ostream &os, const LongNumber& x);


	private:
		int get_length(const char* const str) const noexcept;
		void allocate_and_copy(const int* data, int len);
		void free_memory() noexcept;
	};
}