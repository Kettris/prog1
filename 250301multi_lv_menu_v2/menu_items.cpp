#include "menu_items.hpp"
#include "menu_functions.hpp"

namespace Kate {
const MenuItem* goBack(const MenuItem* currentMenu) {
    return nullptr; 
}

const MenuItem Dubrovsky = {
    "Читать Дубровского", dubrovsky, nullptr, nullptr, 0
};

const MenuItem Eugene_Onegin = {
    "Читать Евгения Онегина", eugene_onegin, nullptr, nullptr, 0
};

const MenuItem Winter_Evening = {
    "Читать Зимний вечер", winter_evening, nullptr, nullptr, 0
};

const MenuItem BACK_TO_PUSHKIN = {
    "Вернуться назад", goBack, nullptr, nullptr, 0
};

namespace {
    const MenuItem* pushkin_children[] = {&Dubrovsky, &Eugene_Onegin, &Winter_Evening, &BACK_TO_PUSHKIN};
    const int pushkin_size = sizeof(pushkin_children) / sizeof(pushkin_children[0]);
}

const MenuItem Pushkin = {
    "Читать Пушкина", read, nullptr, pushkin_children, pushkin_size
};

const MenuItem Lermontov = {
    "Читать Лермонтова", lermontov, nullptr, nullptr, 0
};

const MenuItem Krylov = {
    "Читать Крылова", krylov, nullptr, nullptr, 0
};

const MenuItem MAIN_MENU = {
    "Выйти в главное меню", goBack, nullptr, nullptr, 0
};

namespace {
    const MenuItem* read_children[] = {&Pushkin, &Lermontov, &Krylov, &MAIN_MENU};
    const int read_size = sizeof(read_children) / sizeof(read_children[0]);
}

const MenuItem READ = {
    "Русские писатели", read, nullptr, read_children, read_size
};

const MenuItem EXIT = {
    "Завершить чтение", exit, nullptr, nullptr, 0
};

namespace {
    const MenuItem* main_children[] = {&READ, &EXIT};
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const MenuItem MAIN = {
    "Главное меню", read, nullptr, main_children, main_size
};
}