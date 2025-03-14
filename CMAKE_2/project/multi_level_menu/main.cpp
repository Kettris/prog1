#include <iostream>
#include "menu.hpp"
#include "menu_items.hpp"
#include "menu_functions.hpp"

int main() {
    const Kate::MenuItem* current_menu = &Kate::MAIN_MENU;

    while (true) {
        current_menu = current_menu->action(current_menu);
    }

    return 0;
}