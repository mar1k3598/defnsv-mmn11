#pragma once
#include "Media.h"

#include <iostream>

void Photo::display() {
	std::cout << "\t\timage" << std::endl;
}

void Audio::display() {
	std::cout << "\t\taudio" << std::endl;
}

void Video::display() {
	std::cout << "\t\tvideo" << std::endl;
}