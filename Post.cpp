#pragma once
#include "Post.h"
using namespace std;

Post::Post(string text) {
	// A text only Post instance
	Post::text = text;
}

Post::Post(string text, Media* media) {
	// Constructor with text and media objects
	Post::text = text;
	Post::media = media;
}

string Post::getText() {
	// Returns a copy of the text
	return string(Post::text);
}

Media* Post::getMedia() {
	// Returns the ptr to the local instance of media
	return Post::media;
}