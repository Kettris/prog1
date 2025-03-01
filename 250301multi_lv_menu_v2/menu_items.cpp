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

const Kate::MenuItem Kate::MAIN_MENU = {      // 0 ур
	"0 - Выйти в главное меню", Kate::main_menu, &Kate::READ
};


const Kate::MenuItem Kate::Dubrovsky = {
	"1 - Читать Пушкина", Kate::dubrovsky, &Kate::READ
};

const Kate::MenuItem Kate::Eugene Onegin = {
	"2 - Читать Лермонтова", Kate::eugene onegin, &Kate::READ
};

const Kate::MenuItem Kate::Winter Evening  = {
	"3 - Читать Крылова", Kate::winter evening, &Kate::READ
};

const Kate::MenuItem Kate::MAIN_MENU = {    // 1 ур 
	"0 - Выйти в главное меню", Kate::main_menu, &Kate::READ
};



//анонимное пространство имен
namespace {
	const Kate::MenuItem* const read_children[] = {
		&Kate::MAIN_MENU,  // переход на глав меню (ур 0) ??
		&Kate::Pushkin, 
		&Kate::Lermontov,
		&Kate::Krylov
		&Kate::MAIN_MENU, // переход на пред. меню (ур 1) ??
		&Kate::Dubrovsky, 
		&Kate::Eugene Onegin,
		&Kate::Winter Evening
	};
	const int read_size = sizeof(read_children) / sizeof(read_children[0]);
}

const Kate::MenuItem Kate::READ = {
	"1 - Русские писатели", Kate::read, &Kate::MAIN, read_children, read_size
};

const Kate::MenuItem Kate::EXIT = {
	"0 - Завершить чтение", Kate::exit, &Kate::MAIN
};

const Kate::MenuItem Kate::READ = {
	"3 - Произведения Пушкина", Kate::read, &Kate::MAIN, read_children, read_size
};

namespace {
	const Kate::MenuItem* const main_children[] = {&Kate::EXIT, &Kate::READ};
	const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}


const Kate::MenuItem Kate::MAIN = {
	nullptr, Kate::read, nullptr, main_children, main_size
};