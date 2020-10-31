#pragma once
#include "Media.h"

#include <string>

class Post {
	std::string text;
	Media* media;
public:
	Post(std::string text);
	Post(std::string text, Media* media);
	std::string getText();
	Media* getMedia();
};