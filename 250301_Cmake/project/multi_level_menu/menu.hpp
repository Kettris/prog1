#pragma once

namespace Kate {
    struct MenuItem {
        const char* title;
        const MenuItem* (*action)(const MenuItem* current);
        const MenuItem* parent;
        int children_count = 0;
        const MenuItem* children[4] = {nullptr};
    };
}