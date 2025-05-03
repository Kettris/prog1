#include "vector.hpp"

namespace biv {

template<typename T>
Vector<T>::Vector() {
    arr = new T[capacity];
}

template<typename T>
Vector<T>::~Vector() {
    delete[] arr; //освобождение памяти
}

//метод изменения размера вектора
template<typename T>
void Vector<T>::resize(std::size_t new_capacity) {
    if (new_capacity <= 0) return; //проверка на - размеры
    T* new_arr = new T[new_capacity];
    for (std::size_t i = 0; i < size; ++i) {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    capacity = new_capacity;//обновление
}

template<typename T>
std::size_t Vector<T>::get_size() const noexcept {
    return size;
}

template<typename T>
bool Vector<T>::has_item(const T& value) const noexcept {
    for (std::size_t i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return true;//эл-т найден
        }
    }
    return false;
}

template<typename T>
bool Vector<T>::insert(const std::size_t position, const T& value) {
    if (position > size) return false; //проверка на допустимость позиции
    if (size >= capacity) resize(capacity * 2); //увеличение размера
    //сдвиг эл-ов для вставки
    for (std::size_t i = size; i > position; --i) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value; //вставка эл-а
    ++size; //увеличение размера вектора
    return true;
}

template<typename T>
void Vector<T>::print() const noexcept {
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " "; //печать эл-ов
    }
    std::cout << std::endl;
}

template<typename T>
void Vector<T>::push_back(const T& value) {
    if (size >= capacity) resize(capacity * 2); //увеличение размера
    arr[size++] = value; // Добавление эл-а в конец
}

template<typename T>
bool Vector<T>::remove_first(const T& value) {
//поиск номера элемента для удаления
for (std::size_t i = 0; i < size; ++i) {
    if (arr[i] == value) {  
        //сдвиг остальных элементов
        for (std::size_t j = i; j < size - 1; ++j) {
            arr[j] = arr[j + 1];
        }

        --size; //уменьшаем размер
        
        //проверка на уменьшение размера
        if ((capacity - size) > 200) {
            int new_capacity = size + 100;
            T* temp = new T[new_capacity];
            for (std::size_t i = 0; i < size; i++) {
                temp[i] = arr[i];
            }
            delete arr;
            arr = temp;
        }

        return true;
    }
}
return false;

}

}