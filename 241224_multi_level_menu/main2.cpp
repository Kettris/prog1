#include <clocale>
#include <iostream>

#include "menu.hpp"
#include "menu_functions.hpp"
#include "menu_items.hpp"

int main() {
    std::setlocale(LC_ALL, "");

    const Kate::MenuItem* current = &Kate::MAIN;
    
    do {
        current = Kate::read(current); // используем функцию read для получения следующего пункта меню
    } while (true);
    
    return 0;
}