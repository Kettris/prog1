#include <iostream>

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

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    return 0;
}
