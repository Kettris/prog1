#include "test_QuickSort.hpp"
#include <algorithm> 

namespace sortings {
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1); 
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]); 
            }
        }
        std::swap(arr[i + 1], arr[high]); 
        int partitionIndex = i + 1; 
        quickSort(arr, low, partitionIndex - 1); 
        quickSort(arr, partitionIndex + 1, high);
    }
}
int* quick_sort(const int* const arr, const int size) {
    int* sortedArr = new int[size];
    for (int i = 0; i < size; ++i) {
        sortedArr[i] = arr[i];
    }
    quickSort(sortedArr, 0, size - 1); 
    return sortedArr; 
}
}