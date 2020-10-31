#pragma once
#include <string>

using namespace std;
class Message {
	string text;
public:
	Message(string text);
	~Message();
	string getText();
};