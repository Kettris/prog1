#include "long_number.hpp"
#include <cstring>
#include <algorithm>
#include <stdexcept>

using biv::LongNumber;

// проверка что цифа это символ 
bool is_digit(char c) {
    return (c >= '0' && c <= '9');
}


LongNumber::LongNumber() : numbers(nullptr), length(0), sign(1) {}

//с
LongNumber::LongNumber(const char* const str) : numbers(nullptr), length(0), sign(1) {
    if (str == nullptr) {
        throw std::invalid_argument("Строка не может быть нулевой");
    }

    int str_len = get_length(str);

    if (str_len == 0) {
// пустая неправ строка 
        length = 0;
        numbers = nullptr;
        sign = 1; //положительный ноь
        return;
    }

    int start_index = 0;
    if (str[0] == '-') {
        sign = -1;
        start_index = 1;
    } else if (str[0] == '+') {
        start_index = 1;
    }

// пропуск начальных нулей
    while (start_index < str_len && str[start_index] == '0') {
        start_index++;
    }

// случай, когда вся строка состоит из нулей
    if (start_index == str_len) {
        length = 0;
        numbers = nullptr;
        sign = 1;
        return;
    }

    length = str_len - start_index;
    numbers = new int[length];

    for (int i = 0; i < length; ++i) {
        if (!is_digit(str[start_index + i])) {
            delete[] numbers;
            numbers = nullptr;
            length = 0;
            sign = 1;
            throw std::invalid_argument("Недопустимый символ в строке");
        }
        numbers[i] = str[start_index + i] - '0';
    }
}


// Конструктор копирования
LongNumber::LongNumber(const LongNumber& x) : numbers(nullptr), length(x.length), sign(x.sign) {
    allocate_and_copy(x.numbers, x.length);
}

// Конструктор перемещения
LongNumber::LongNumber(LongNumber&& x) : numbers(x.numbers), length(x.length), sign(x.sign) {
    x.numbers = nullptr;
    x.length = 0;
    x.sign = 1;
}

// Деструктор
LongNumber::~LongNumber() {
    free_memory();
}

LongNumber& LongNumber::operator = (const char* const str) {
    LongNumber temp(str); // создан временый LongNumber
    *this = std::move(temp); 
    return *this;
}

//копирование опер присваивания 
LongNumber& LongNumber::operator = (const LongNumber& x) {
    if (this != &x) {
        free_memory();
        length = x.length;
        sign = x.sign;
        allocate_and_copy(x.numbers, x.length);
    }
    return *this;
}

//присваивание
LongNumber& LongNumber::operator = (LongNumber&& x) {
    if (this != &x) {
        free_memory();
        numbers = x.numbers;
        length = x.length;
        sign = x.sign;

        x.numbers = nullptr;
        x.length = 0;
        x.sign = 1;
    }
    return *this;
}


bool LongNumber::operator == (const LongNumber& x) const {
    if (sign != x.sign) return false;
    if (length != x.length) return false;

    for (int i = 0; i < length; ++i) {
        if (numbers[i] != x.numbers[i]) return false;
    }

    return true;
}

//неравенство
bool LongNumber::operator != (const LongNumber& x) const {
    return !(*this == x);
}


bool LongNumber::operator > (const LongNumber& x) const {
    if (sign > x.sign) return true;
    if (sign < x.sign) return false;

    if (sign == 1) { // оба +
        if (length > x.length) return true;
        if (length < x.length) return false;

        for (int i = 0; i < length; ++i) {
            if (numbers[i] > x.numbers[i]) return true;
            if (numbers[i] < x.numbers[i]) return false;
        }
        return false; 
    } else if (sign == -1) { // оба -
        if (length < x.length) return true;
        if (length > x.length) return false;

        for (int i = 0; i < length; ++i) {
            if (numbers[i] < x.numbers[i]) return true;
            if (numbers[i] > x.numbers[i]) return false;
        }
        return false; 
    } else {
        return false;
    }
}


bool LongNumber::operator < (const LongNumber& x) const {
    return !(*this > x) && !(*this == x);
}

bool LongNumber::operator >= (const LongNumber& x) const {
    //сравнение знаков
    if (sign > x.sign) return true;
    if (sign < x.sign) return false;

    // сравниваем длину
    if (length > x.length) return sign == 1; //+
    if (length < x.length) return sign == -1; //-

    // сравниваем по значениям
    for (int i = 0; i < length; ++i) {
        if (numbers[i] > x.numbers[i]) return sign == 1;
        if (numbers[i] < x.numbers[i]) return sign == -1;
    }

    return true; // Они равны
}


//сложение 
LongNumber LongNumber::operator + (const LongNumber& x) const {
    // cложение двух нулей
    if (length == 0 && x.length == 0) {
        return LongNumber("0");
    }

    int abs_this_length = length;
    int abs_x_length = x.length;

    if (sign != x.sign) {
        if (sign == -1) {
            LongNumber pos = *this;// -++=+-
             pos.sign = 1; 
            return x - pos; 
        }
        else {
            LongNumber neg = x; // ++-=+-
            neg.sign = 1;
            return *this - neg; 
        }
    }


    // оба + или -
    int result_sign = sign; //сохран знак 
    int result_length = std::max(length, x.length) + 1;
    int* result_numbers = new int[result_length]();
    int carry = 0;

    for (int i = 0; i < result_length; ++i) {
        int digit1 = (i < length) ? numbers[length - 1 - i] : 0;
        int digit2 = (i < x.length) ? x.numbers[x.length - 1 - i] : 0;

        int sum = digit1 + digit2 + carry;
        result_numbers[result_length - 1 - i] = sum % 10;
        carry = sum / 10; 
    }

    // если  остался перенос
    if (carry > 0) {
        result_numbers[0] = carry;
    }

    // удал ненуж нулей
    int start_index = 0; 
    while (start_index < result_length - 1 && result_numbers[start_index] == 0) {
        start_index++;
    }

    int final_length = result_length - start_index;
    int* final_numbers = new int[final_length];
    std::memcpy(final_numbers, result_numbers + start_index, final_length * sizeof(int));
    
    delete[] result_numbers;//освобожден массива

    LongNumber result;
    result.numbers = final_numbers;
    result.length = final_length;
    result.sign = result_sign;

    return result;
}

//вычитание
LongNumber LongNumber::operator - (const LongNumber& x) const {
// разные знаки --=+
    if (sign != x.sign) {
        LongNumber temp = x;
        temp.sign = sign;
        return *this + temp;
    }

// Оба положительных или оба отрицательных
    int compare = 0;
    if (*this > x) {
        compare = 1;
    } else if (*this < x) {
        compare = -1;
    }

    if (compare == 0) {
        return LongNumber("0");
    }

    int result_sign = (compare == 1) ? sign : -sign;
    const LongNumber& larger = (compare == 1) ? *this : x;
    const LongNumber& smaller = (compare == 1) ? x : *this;

    int result_length = larger.length;
    int* result_numbers = new int[result_length];
    std::memset(result_numbers, 0, result_length * sizeof(int));

    int borrow = 0;
    for (int i = 0; i < larger.length; ++i) {
        int digit1 = (i < larger.length) ? larger.numbers[larger.length - 1 - i] : 0;
        int digit2 = (i < smaller.length) ? smaller.numbers[smaller.length - 1 - i] : 0;

        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result_numbers[result_length - 1 - i] = diff;
    }


    int start_index = 0;
    while (start_index < result_length - 1 && result_numbers[start_index] == 0) {
        start_index++;
    }

    int final_length = result_length - start_index;
    int* final_numbers = new int[final_length];
    std::memcpy(final_numbers, result_numbers + start_index, final_length * sizeof(int));

    delete[] result_numbers;

    LongNumber result;
    result.numbers = final_numbers;
    result.length = final_length;
    result.sign = result_sign;

    return result;
}

// Умножение
LongNumber LongNumber::operator*(const LongNumber& x) const {
   
    //проверка на ноль
    if (length == 0 || x.length == 0) {
        return LongNumber("0");
    }

    //знак и длина результата
    int result_sign = sign * x.sign;
    int result_length = length + x.length;
    int* result_numbers = new int[result_length]();

    //разрядное умножение
    for (int i = length - 1; i >= 0; --i) {
        for (int j = x.length - 1; j >= 0; --j) {
            result_numbers[i + j + 1] += numbers[i] * x.numbers[j];
        }
    }

    //перенос
    for (int i = result_length - 1; i > 0; --i) {
        result_numbers[i - 1] += result_numbers[i] / 10;
        result_numbers[i] %= 10;
    }

    //определение длины результата
    LongNumber result;
    int start_index = 0;
    while (start_index < result_length && result_numbers[start_index] == 0) {
        start_index++;
    }
    result.length = result_length - start_index;

    //если длина 0, то возвращаем 0
    if (result.length == 0) {
        delete[] result_numbers;
        result.numbers = nullptr;
        result.sign = 1; 
        return result;
    }

    result.numbers = new int[result.length];
    for (int i = 0; i < result.length; ++i) {
        result.numbers[i] = result_numbers[start_index + i];
    }

    // Устанавливаем знак результата
    result.sign = result_sign;
    delete[] result_numbers;
    return result;
}

// Деление
LongNumber LongNumber::operator/(const LongNumber& x) const {
    
    // Проверка на деление на ноль
    if (x.length == 0 || (x.length == 1 && x.numbers[0] == 0)) {
        throw std::invalid_argument("Деление на ноль");
    }

    LongNumber divisor = x;//делитель
    LongNumber dividend = *this;//делимое

    //знак результата
    int sign_result = (sign == divisor.sign) ? 1 : -1;

    //приводим к полож числам
    dividend.sign = 1;
    divisor.sign = 1;

    //если делимое меньше делителя, результат - 0
    if (dividend < divisor) {
        return LongNumber("0");
    }

    LongNumber quotient("0");
    LongNumber one("1");

    //цикл деления 
    while (dividend >= divisor) {
        dividend = dividend - divisor; //уменьшение
        quotient = quotient + one;
    }

    // удаляем начальные нули
    if (quotient.length == 0) {
        quotient = LongNumber("0");
    }

    // устанавливаем знак у результата деления
    quotient.sign = sign_result;

    return quotient;
}

LongNumber LongNumber::operator%(const LongNumber& x) const {
    if (x.length == 0 || (x.length == 1 && x.numbers[0] == 0)) {
        throw std::invalid_argument("Деление на ноль");
    }

    LongNumber divisor = x; // делитель
    LongNumber dividend = *this; // делимое

    // Переводим числа в положительные
    LongNumber absDividend = dividend;
    LongNumber absDivisor = divisor;

    absDividend.sign = 1; // делимое +
    absDivisor.sign = 1; // делитель +

    // Если делимое < делителя, остаток = делимому
    if (absDividend < absDivisor) {
        return (dividend.is_negative() && absDivisor > absDividend) ? 
               LongNumber(absDivisor - absDividend) : absDividend;
    }

    while (absDividend >= absDivisor) {
        absDividend = absDividend - absDivisor;
    }

    // Установка знака для остатка
    // Остаток от деления будет иметь тот же знак, что и делимое
    if (dividend.is_negative()) {
        // Приводим к абсолютному значению остатка, если делимое было отрицательным
        absDividend = absDivisor - absDividend;
        if (absDividend < absDivisor) {
            return absDividend; // возвращаем остаток с корректным знаком
        }
    }

    return absDividend;
}


    bool LongNumber::is_negative() const noexcept { 
        return sign == -1;  
    }


    int LongNumber::get_length(const char* const str) const noexcept {
        if (str == nullptr) return 0;
        return std::strlen(str);
    }


    void LongNumber::allocate_and_copy(const int* data, int len) {
        if (len > 0) {
            numbers = new int[len];
            std::memcpy(numbers, data, len * sizeof(int));
        } else {
            numbers = nullptr;
        }
        length = len;
    }


    void LongNumber::free_memory() noexcept {
        delete[] numbers;
        numbers = nullptr;
        length = 0;
    }

    // для обработки операций вывода
    namespace biv {

    std::ostream& operator<<(std::ostream &os, const LongNumber& x) { 
        if (x.numbers == nullptr || x.length == 0) {
            os << "0";
            return os;
        }
        if (x.sign == -1) {
            os << "-";
        }
        for (int i = 0; i < x.length; ++i) {
            os << x.numbers[i];
        }
        return os;
    }

    } 