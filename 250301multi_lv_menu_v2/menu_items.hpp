#pragma once
#include "menu.hpp"

namespace Kate {

    // Объявления основных пунктов меню
    extern const MenuItem MAIN;
    extern const MenuItem READ; 
    extern const MenuItem EXIT; 

    // Объявления пунктов меню для "Читать"
    extern const MenuItem Pushkin; 
    extern const MenuItem Lermontov;
    extern const MenuItem Krylov; 

    // Объявления пунктов меню для "Читать" Пушкина
    extern const MenuItem Dubrovsky;
    extern const MenuItem Eugene_Onegin; 
    extern const MenuItem Winter_Evening;

    const MenuItem* goBack(const MenuItem* currentMenu);
}