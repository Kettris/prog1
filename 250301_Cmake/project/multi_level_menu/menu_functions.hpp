#pragma once 
#include "menu.hpp"

namespace Mine {
	const MenuItem* exit(const MenuItem* current);
	const MenuItem* read(const MenuItem* current);
	
	const MenuItem* pushkin(const MenuItem* current);
	const MenuItem* lermontov(const MenuItem* current);
	const MenuItem* krylov(const MenuItem* current);
	const MenuItem* main_menu(const MenuItem* current);
}