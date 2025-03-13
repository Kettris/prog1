#include "menu_items.hpp"
#include "menu_functions.hpp"

// 3 уровень
const Kate::MenuItem Kate::DUBROVSKY = {
    "Читать Дубровского", Kate::dubrovsky, &Kate::PUSHKIN
};
const Kate::MenuItem Kate::EUGENE_ONEGIN = {
    "Читать Евгения Онегина", Kate::eugene_onegin, &Kate::PUSHKIN
};
const Kate::MenuItem Kate::WINTER_EVENING = {
    "Читать Зимний вечер", Kate::winter_evening, &Kate::PUSHKIN
};
//исправить
const Kate::MenuItem Kate::BACK_TO_PUSH = {
    "Вернуться назад", Kate::back, &Kate::RUSSIAN_WRITERS
};

const Kate::MenuItem Kate::PUSHKIN = {
    "Читать Пушкина", Kate::read, &Kate::RUSSIAN_WRITERS,
    4, {&Kate::DUBROVSKY, &Kate::EUGENE_ONEGIN, &Kate::WINTER_EVENING, &Kate::BACK_TO_PUSH}
};

const Kate::MenuItem Kate::LERMONTOV = {
    "Читать Лермонтова", Kate::lermontov, &Kate::RUSSIAN_WRITERS
};
const Kate::MenuItem Kate::KRYLOV = {
    "Читать Крылова", Kate::krylov, &Kate::RUSSIAN_WRITERS
};

const Kate::MenuItem Kate::BACK_TO_MAIN = {
    "Выйти в главное меню", Kate::back_to_main_menu, &Kate::RUSSIAN_WRITERS
};

const Kate::MenuItem Kate::RUSSIAN_WRITERS = {
    "Русские писатели", Kate::read, &Kate::MAIN_MENU,
    4, {&Kate::PUSHKIN, &Kate::LERMONTOV, &Kate::KRYLOV, &Kate::BACK_TO_MAIN}
};

const Kate::MenuItem Kate::EXIT = {
    "Завершить чтение", Kate::exit_program, &Kate::MAIN_MENU
};

const Kate::MenuItem Kate::MAIN_MENU = {
    "Главное меню", Kate::read, nullptr,
    2, {&Kate::RUSSIAN_WRITERS, &Kate::EXIT}
};

const Kate::MenuItem* Kate::CURRENT_MENU = &Kate::MAIN_MENU;