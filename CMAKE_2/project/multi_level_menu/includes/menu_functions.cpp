#include <cstdlib>
#include <iostream>
#include "menu_functions.hpp"

const Kate::MenuItem* Kate::exit_program(const MenuItem* current) {
    std::exit(0);
    return nullptr; 
}

const Kate::MenuItem* Kate::read(const MenuItem* current) {
    for (int i = 0; i < current->children_count; ++i) {
        std::cout << i + 1 << " - " << current->children[i]->title << std::endl;
    }

    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    // Проверка на корректность ввода
    if (user_input > 0 && user_input <= current->children_count) {
        return current->children[user_input - 1];
    } else {
        std::cout << "Некорректный ввод. Пожалуйста, выберите пункт меню из списка." << std::endl;
        return current; // Возврат в меню
    }
}

const Kate::MenuItem* Kate::pushkin(const MenuItem* current) {
    std::cout << "Вы выбрали: " << current->title << std::endl;
    return current->parent;
}

const Kate::MenuItem* Kate::lermontov(const MenuItem* current) {
    std::cout << "Вы выбрали: " << current->title << std::endl;
    return current->parent;
}

const Kate::MenuItem* Kate::krylov(const MenuItem* current) {
    std::cout << "Вы выбрали: " << current->title << std::endl;
    return current->parent;
}

const Kate::MenuItem* Kate::back_to_main_menu(const MenuItem* current) {
    std::cout << "Возврат в главное меню." << std::endl;
    return current->parent->parent; // Возврат
}

// 3 уровень
const Kate::MenuItem* Kate::dubrovsky(const MenuItem* current) {
    std::cout << "Вы выбрали: " << current->title << std::endl;
    return current->parent;
}

const Kate::MenuItem* Kate::eugene_onegin(const MenuItem* current) {
    std::cout << "Вы выбрали: " << current->title << std::endl;
    return current->parent;
}

const Kate::MenuItem* Kate::winter_evening(const MenuItem* current) {
    std::cout << "Вы выбрали: " << current->title << std::endl;
    return current->parent;
}

const Kate::MenuItem* Kate::back(const MenuItem* current) {
    std::cout << "Возврат на предыдущий уровень." << std::endl;
    return current->parent;
}