#pragma once
#include "Media.h"
#include <string>

class Post {
private:
	std::string text;
	Media* media;
public:
	Post(std::string text);
	Post(std::string text, Media* media);
	~Post();
	std::string getText();
	Media* getMedia();
};