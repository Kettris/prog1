#include <gmock/gmock.h>
#include <gtest/gtest.h>
//#include "QuickSort.hpp"
#include "quick_sort.hpp"

TEST(QuickSortTest, SortsArrayCorrectly) {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int expected[] = {1, 5, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortings::quickSort(arr, 0, n - 1);

    ASSERT_EQ(sizeof(expected) / sizeof(expected[0]), n)
        << "Размеры ожидаемого и отсортированного массивов не совпадают";

    for (int i = 0; i < n; i++) {
        ASSERT_EQ(expected[i], arr[i]) 
            << "Массив ожидаемый и отсортированный отличаются в элементе с индексом " << i;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}