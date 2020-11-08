#include "Message.h"

Message::Message(std::string text) : _text(text) {
	return;
}

std::string Message::getText()
{
	return std::string(_text);
}
