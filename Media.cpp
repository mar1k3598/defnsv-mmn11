#pragma once
#include "Media.h"

#include <iostream>

void Photo::display() {
	std::cout << "image" << std::endl;
}

void Audio::display() {
	std::cout << "audio" << std::endl;
}

void Video::display() {
	std::cout << "video" << std::endl;
}