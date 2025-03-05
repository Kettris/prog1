#include <cstdlib>
#include <iostream>

#include "menu_functions.hpp"

namespace Kate {
const MenuItem* read(const MenuItem* current) {
    // Показать меню текущего уровня
    for (int i = 0; i < current->children_count; ++i) {
        std::cout << i << ": " << current->children[i]->title << std::endl;               
    }
    
    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    if (user_input >= 0 && user_input < current->children_count) {
        const MenuItem* next = current->children[user_input]->func(current->children[user_input]);
        return next; 
    } else {
        std::cout << "Неверный ввод. Попробуйте снова." << std::endl;
        return current; // Вернуться к текущему меню
    }
}

const MenuItem* exit(const MenuItem* current) {
    std::cout << "Завершение программы." << std::endl;
    std::exit(0);
}

const MenuItem* pushkin(const MenuItem* current) {
    std::cout << "Вы выбрали Пушкина." << std::endl << std::endl;
    return current; 
}

const MenuItem* lermontov(const MenuItem* current) {
    std::cout << "Вы выбрали Лермонтова." << std::endl << std::endl;
    return current; 
}

const MenuItem* krylov(const MenuItem* current) {
    std::cout << "Вы выбрали Крылова." << std::endl << std::endl;
    return current; 
}

const MenuItem* dubrovsky(const MenuItem* current) {
    std::cout << "Выбран: " << current->title << std::endl << std::endl;
    return current;
}

const MenuItem* eugene_onegin(const MenuItem* current) {
    std::cout << "Выбран: " << current->title << std::endl << std::endl;
    return current;
}

const MenuItem* winter_evening(const MenuItem* current) {
    std::cout << "Выбран: " << current->title << std::endl << std::endl;
    return current;
}

} // namespace Kate