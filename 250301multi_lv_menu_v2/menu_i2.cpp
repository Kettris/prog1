#include "menu_items.hpp"
#include "menu_functions.hpp"


const Kate::MenuItem Kate::Pushkin = {
    "1 - Читать Пушкина", Kate::pushkin, &Kate::READ
};

const Kate::MenuItem Kate::Lermontov = {
    "2 - Читать Лермонтова", Kate::lermontov, &Kate::READ
};

const Kate::MenuItem Kate::Krylov = {
    "3 - Читать Крылова", Kate::krylov, &Kate::READ
};


const Kate::MenuItem Kate::Dubrovsky = {
    "1 - Читать Дубровского", Kate::dubrovsky, &Kate::MAIN_MENU 
};

const Kate::MenuItem Kate::Eugene_Onegin = { 
    "2 - Читать Евгения Онегина", Kate::eugene_onegin, &Kate::MAIN_MENU 
};

const Kate::MenuItem Kate::Winter_Evening = { 
    "3 - Читать Зимний вечер", Kate::winter_evening, &Kate::MAIN_MENU 
};

const Kate::MenuItem Kate::MAIN_MENU = {
    "0 - Выйти в главное меню", Kate::main_menu, nullptr

namespace {
    const Kate::MenuItem* const read_children[] = {
        &Kate::Dubrovsky,
        &Kate::Eugene_Onegin,
        &Kate::Winter_Evening,
        &Kate::MAIN_MENU
    };
    const int read_size = sizeof(read_children) / sizeof(read_children[0]);
}

const Kate::MenuItem Kate::READ = {
    "1 - Русские писатели", Kate::read, nullptr, read_children, read_size
};

const Kate::MenuItem Kate::EXIT = {
    "0 - Завершить чтение", Kate::exit, nullptr 
};

namespace {
    const Kate::MenuItem* const main_children[] = {
        &Kate::EXIT,
        &Kate::READ
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const Kate::MenuItem Kate::MAIN = {
    "Главное меню", Kate::read, nullptr, main_children, main_size
};