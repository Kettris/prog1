#pragma once

namespace Kate {
    struct MenuItem {
        const char* const title;
        const MenuItem* (*func)(const MenuItem* current);
        const MenuItem* parent;
        const MenuItem** children;
        const int children_count;

        MenuItem(const char* title, const MenuItem* (*func)(const MenuItem*), const MenuItem* parent, const MenuItem** children, int children_count)
            : title(title), func(func), parent(parent), children(children), children_count(children_count) {}
    };
}