#include <iostream>
#include "quick_sort.hpp"

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5}; // пример массива
    int n = sizeof(arr) / sizeof(arr[0]); // вычисляем размер массива
    quickSort(arr, 0, n - 1); // вызываем функцию быстрой сортировки

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " "; // выводим отсортированный массив
    std::cout << std::endl;

    return 0; // завершение программы
}