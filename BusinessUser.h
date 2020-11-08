#pragma once
#include "User.h"

class BusinessUser : public User {
	friend class USocial;
	BusinessUser(std::string username, USocial* social_net, const unsigned int id);
public:
	void sendMessage(User* user, Message* msg);
};