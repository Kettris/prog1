#include <iostream>
#include <vector>

int main() {
    int day;
    std::cout << "Введите номер дня недели (1 - Понедельник, 7 - Воскресенье): ";
    std::cin >> day;

    // Проверка на корректность ввода
    if (day < 1 || day > 7) {
        std::cerr << "Ошибка: Неверный номер дня недели!" << std::endl;
        return 1; // Завершение программы с ошибкой
    }

    // Список дней недели
    std::vector<std::string> daysOfWeek = {
        "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье"
    };

    // Вывод оставшихся дней недели
    std::cout << "Оставшиеся дни недели:" << std::endl;
    for (int i = day - 1; i < daysOfWeek.size(); ++i) {
        std::cout << daysOfWeek[i] << std::endl;
    }

    return 0;
}