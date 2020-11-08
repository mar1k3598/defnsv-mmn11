#pragma once
#include <string>

class Message {
private:
	const std::string _text;
public:
	Message(std::string text);
	std::string getText();
};