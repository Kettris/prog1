#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

namespace Kate {

    const MenuItem* read(const MenuItem* current) {
        for (int i = 0; i < current->children_count; ++i) {
            std::cout << i << ". " << current->children[i]->title << std::endl; 
        }
        
        int user_input;
        std::cin >> user_input;
        std::cout << std::endl;

        if (user_input < 0 || user_input >= current->children_count) { 
            std::cout << "Неверный ввод. Попробуйте снова." << std::endl;
            return current;
        }
        
        return current->children[user_input];
    }

    const MenuItem* exit(const MenuItem* current) {
        std::exit(0);
    }

    const MenuItem* pushkin(const MenuItem* current) {
        std::cout << current->title << std::endl << std::endl;
        return read(current); 
    }

    const MenuItem* lermontov(const MenuItem* current) {
        std::cout << current->title << std::endl << std::endl;
        return current->parent;
    }

    const MenuItem* krylov(const MenuItem* current) {
        std::cout << current->title << std::endl << std::endl;
        return current->parent;
    }

    const MenuItem* main_menu(const MenuItem* current) {
        std::cout << current->title << std::endl << std::endl;
        return current->parent->parent;
    }

    const MenuItem* dubrovsky(const MenuItem* current) {
        std::cout << current->title << std::endl << std::endl;
        return current->parent;
    }

    const MenuItem* eugene_onegin(const MenuItem* current) {
        std::cout << current->title << std::endl << std::endl;
        return current->parent;
    }

    const MenuItem* winter_evening(const MenuItem* current) {
        std::cout << current->title << std::endl << std::endl;
        return current->parent;
    }
}