﻿#include "menu_items.hpp"
#include "menu_functions.hpp"

const Mine::MenuItem Mine::PUSHKIN = {
	"1 - Читать Пушкина", Mine::pushkin, &Mine::READ
};

const Mine::MenuItem Mine::LERMONTOV = {
	"2 - Читать Лермонтова", Mine::lermontov, &Mine::READ
};

const Mine::MenuItem Mine::KRYLOV = {
	"3 - Читать Крылова", Mine::krylov, &Mine::READ
};

const Mine::MenuItem Mine::MAIN_MENU = {
	"0 - Выйти в главное меню", Mine::main_menu, &Mine::READ
};

namespace {
	const Mine::MenuItem* const read_children[] = {&Mine::MAIN_MENU, &Mine::PUSHKIN, &Mine::LERMONTOV, &Mine::KRYLOV};
	const int read_size = sizeof(read_children) / sizeof(read_children[0]);
}

const Mine::MenuItem Mine::READ = {
	"1 - Русские писатели", Mine::read, &Mine::MAIN, read_children, read_size
};

const Mine::MenuItem Mine::EXIT = {
	"0 - Завершить чтение", Mine::exit, &Mine::MAIN
};

namespace {
	const Mine::MenuItem* const main_children[] = {&Mine::EXIT, &Mine::READ};
	const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}


const Mine::MenuItem Mine::MAIN = {
	nullptr, Mine::read, nullptr, main_children, main_size
};