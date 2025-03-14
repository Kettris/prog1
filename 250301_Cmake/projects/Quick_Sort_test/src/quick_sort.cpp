#include "test_QuickSort.hpp"
#include <algorithm> // для std::swap

namespace sortings {

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high]; // выбираем последний элемент как опорный
        int i = (low - 1); // индекс меньшего элемента

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]); // меняем местами
            }
        }
        std::swap(arr[i + 1], arr[high]); // меняем опорный элемент на позицию i+1
        
        int partitionIndex = i + 1; // индекс разделения

        quickSort(arr, low, partitionIndex - 1); // рекурсивно сортируем элементы до разделения
        quickSort(arr, partitionIndex + 1, high); // и после разделения
    }
}

int* quick_sort(const int* const arr, const int size) {
    int* sortedArr = new int[size];
    
    // Копируем массив в новый массив для сортировки
    for (int i = 0; i < size; ++i) {
        sortedArr[i] = arr[i];
    }

    quickSort(sortedArr, 0, size - 1); // вызываем функцию быстрой сортировки
    return sortedArr; // возвращаем отсортированный массив
}

}