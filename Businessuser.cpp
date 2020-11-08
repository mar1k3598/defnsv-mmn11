#ifndef _BUSINESSUSER_H
#define _BUSINESSUSER_H

#include "BusinessUser.h"

void BusinessUser::sendMessage(User* user, Message* msg) {
	user->receiveMessage(msg);
}

BusinessUser::BusinessUser(std::string username, USocial* social_net ,const unsigned int id) : 
	User(username, social_net, id) 
{
}
#endif