#include <iostream>

using namespace std;
int main()
{
    double a[10]; // Массив для хранения элементов
    // Ввод элементов массива
    for (int i = 0; i < 10; i++){
        cout << "Введите " << i + 1 << " элемент" << endl;
        cin >> a[i];
    }

    bool isIncreasing = true; // Флаг для проверки возрастающей последовательности

    // Проверка последовательности
    for (int i = 0; i < 9; i++){ // Изменено условие, чтобы не выходить за пределы массива
        if (a[i] > a[i + 1]){ // Если текущий элемент больше следующего
            isIncreasing = false; // Устанавливаем флаг в false
            break; // Прерываем цикл, если последовательность не возрастающая
        }
    }

    // Вывод результата
    if (isIncreasing) {
        cout << "последовательность возрастает" << endl;
    }
	else {
        cout << "последовательность не возрастает" << endl;
    }
    return 0;
}