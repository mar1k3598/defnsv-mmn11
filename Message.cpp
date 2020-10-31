#include "Message.h"

Message::~Message()
{
}

string Message::getText()
{
	return string(text);
}
