#pragma once
#include "Post.h"

Post::Post(std::string _text) {
	// A text only Post instance
	text = _text;
	media = NULL;
}

Post::Post(std::string _text, Media* _media) {
	// Constructor with text and media objects
	text = _text;
	media = _media;
}

Post::~Post() {
	delete media;
}

std::string Post::getText() {
	return std::string(text);
}

Media* Post::getMedia() {
	return media;
}