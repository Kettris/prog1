#pragma once
#include "menu.hpp"

namespace Kate {
    const MenuItem* exit_program(const MenuItem* current);
    const MenuItem* read(const MenuItem* current);
    const MenuItem* pushkin(const MenuItem* current);
    const MenuItem* lermontov(const MenuItem* current);
    const MenuItem* krylov(const MenuItem* current);
    const MenuItem* back_to_main_menu(const MenuItem* current);

    // 3 уровень
    const MenuItem* dubrovsky(const MenuItem* current);
    const MenuItem* eugene_onegin(const MenuItem* current);
    const MenuItem* winter_evening(const MenuItem* current);
    const MenuItem* back(const MenuItem* current);
}