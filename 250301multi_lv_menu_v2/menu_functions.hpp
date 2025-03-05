#pragma once 
#include "menu.hpp"

namespace Kate {
    const MenuItem* read(const MenuItem* current);
    const MenuItem* exit(const MenuItem* current);

    const MenuItem* pushkin(const MenuItem* current);
    const MenuItem* lermontov(const MenuItem* current);
    const MenuItem* krylov(const MenuItem* current);
    const MenuItem* dubrovsky(const MenuItem* current);
    const MenuItem* eugene_onegin(const MenuItem* current); 
    const MenuItem* winter_evening(const MenuItem* current);

}