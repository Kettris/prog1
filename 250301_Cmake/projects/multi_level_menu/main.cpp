#include <iostream>
#include "includes/menu_items.hpp"

int main() {
    const Kate::MenuItem* current_menu = &Kate::MAIN_MENU;
    
	while (true) {
        current_menu = current_menu->action(current_menu);
    }
    return 0;
}