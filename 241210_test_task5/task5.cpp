#include <iostream>

int main() {
    int day;
    std::cout << "Введите номер дня недели (1 - Понедельник, 7 - Воскресенье): ";
    std::cin >> day;

  if (day > 1 && day < 7) {
		const char* daysOfWeek [] = {
			"Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье"
		};
		const int size = sizeof(daysOfWeek) / sizeof(daysOfWeek[0]);

		std::cout << "Оставшиеся дни недели:" << std::endl;
		for (int i = day - 1; i < size; ++i) {
			std::cout << daysOfWeek[i] << std::endl;
		}
    } else {
		std::cerr << "Ошибка: Неверный номер дня недели!" << std::endl;
	}
    return 0;
}
