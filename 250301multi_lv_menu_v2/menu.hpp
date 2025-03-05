#pragma once

namespace Kate {
    struct MenuItem {
        const char* const title; // Заголовок меню
        const MenuItem* (*func)(const MenuItem*); // Указатель на функцию, связанную с элементом меню
        const MenuItem* parent; // Родительский элемент меню
        const MenuItem** children; // Дочерние элементы меню
        const int children_count; // Количество дочерних элементов

        // Конструктор структуры MenuItem
        MenuItem(const char* title, const MenuItem* (*func)(const MenuItem*), const MenuItem* parent, const MenuItem** children, int children_count)
            : title(title), func(func), parent(parent), children(children), children_count(children_count) {}
    };
}