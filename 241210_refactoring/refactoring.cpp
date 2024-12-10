#include <iostream>

using namespace std;
int main()
{
	const int size = 10;
    double arr[size];
    for (int i = 0; i < size; i++){
        cout << "Введите " << i + 1 << " элемент" << endl;
        cin >> arr[i];
    }

    bool isIncreasing = true; 

    for (int i = 0; i < size - 1; i++){ 
        if (arr[i] > arr[i + 1]){ 
            isIncreasing = false; 
            break; 
        }
    }

    if (isIncreasing) {
        cout << "последовательность возрастает" << endl;
    }
	else {
        cout << "последовательность не возрастает" << endl;
    }
    return 0;
}