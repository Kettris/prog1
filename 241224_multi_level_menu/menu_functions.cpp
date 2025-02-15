#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>


const Kate::MenuItem* Kate::read(const MenuItem* current) {
	for (int i = 1; i < current->children_count; ++i){
		std::cout << current->children[i]->title << std::endl;	           
	}
	std::cout << current->children[0]->title << std::endl;
	
	int user_input;
	std::cin >> user_input;
	std::cout << std::endl;
	
	return current->children[user_input];
}

const Kate::MenuItem* Kate::exit(const MenuItem* current) {
	std::exit(0);
}

const Kate::MenuItem* Kate::pushkin(const MenuItem* current){
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}

const Kate::MenuItem* Kate::lermontov(const MenuItem* current){
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}

const Kate::MenuItem* Kate::krylov(const MenuItem* current){
	std::cout << current->title << std::endl << std::endl;
	return current->parent;
}

const Kate::MenuItem* Kate::main_menu(const MenuItem* current){
	std::cout << current->title << std::endl << std::endl;
	return current->parent->parent;
}