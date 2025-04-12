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

    // разный знак
//    if (sign != x.sign) {
//        LongNumber temp = x;
//        temp.sign = -x.sign; 
//        return *this - temp; 
//    }
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
LongNumber LongNumber::operator * (const LongNumber& x) const {
    // Проверка на ноль
    if (length == 0 || x.length == 0) {
        return LongNumber("0"); // Умножение на ноль
    }

    if ((length == 1 && numbers [0] == 1)) {
        return x;
    }
    if ((x.length == 1 && x.numbers [0] == 1)) {
        return *this;
    }

 
    // Длина результата
    int result_length = length + x.length; 
    int* result_numbers = new int[result_length](); 

    // Умножаем числа
    for (int i = length - 1; i >= 0; ++i) {
        for (int j = x.length - 1; j >= 0; ++j) {
            result_numbers[result_length - 1 -(i + j)] += result_numbers[i] * (j < x.length? x.numbers[j]: 0);
          // Перенос
            /*result_numbers[result_length - 1 - (i + j)] += result_numbers[result_length - 1 - (i + j + 1)] / 10;
            carry = result_numbers[result_length - 1 - (i + j + 1)] = result_numbers[result_length - 1 - (i + j)] % 10;*/
        }
    }
    for (int i = result_length - 1; i >= 0; ++i){
        if (result_numbers[i] > 9){
            int temp = result_numbers[i];
            result_numbers[i] = temp % 10;
            result_numbers[i + 1] += temp / 10;


        }
    }

    // Создаем результат
    LongNumber result;
    int start_index = 0;

    // Пропускаем начальные нули
    while (start_index < result_length - 1 && result_numbers[start_index] == 0) {
        start_index++;
    }

    // Устанавливаем длину результата
    result.length = result_length - start_index;

    // Если длина равна 0, значит результат равен 0
    if (result.length == 0) {
        delete[] result_numbers;
        result.numbers = nullptr; // Знак для 0
        result.sign = 1; 
        return result;
    }

    // Копируем результат   
    result.numbers = new int[result.length];
    for (int i = 0; i < result.length; ++i) {
        result.numbers[i] = result_numbers[start_index + i];
    }

    // Рассчитываем знак результата
    result.sign = (sign * x.sign);

    delete[] result_numbers; // Освобождаем память
    return result;
}
// деление
LongNumber LongNumber::operator/(const LongNumber& x) const {
    if (x.length == 0 || (x.length == 1 && x.numbers[0] == 0)) {
        throw std::invalid_argument("Деление на ноль");
    }

    LongNumber result;
    result.sign = sign * x.sign;
    result.numbers = new int[length]();
    result.length = length;

    LongNumber remainder = *this;
    remainder.sign = 1;

    for (int i = length - 1; i >= 0; --i) {
            // Добавляем очередную цифру к остатку
        LongNumber temp("0"); // создаем временно LongNumber из "0"
        temp.numbers[0] = numbers[i]; // добавляем текущую цифру
        temp.length = 1;
        remainder = remainder * LongNumber("10") + temp;
        int count = 0;
        while (remainder >= x) {
            remainder = remainder - x;
            count++;
        }
        result.numbers[i] = count;
    }

    while (result.length > 1 && result.numbers[result.length - 1] == 0) {
        result.length--;
    }

    return result;
}
    

// с остатком
LongNumber LongNumber::operator % (const LongNumber& x) const {
    LongNumber quotient = *this / x;
    LongNumber product = quotient * x;
    return *this - product;
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
