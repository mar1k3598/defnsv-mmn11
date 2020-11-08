#pragma once
#ifndef _USOCIAL_H
#define _USOCIAL_H
#include <string>
#include <map>
#include <stdlib.h>
#include <time.h>

class User;
class USocial {
	std::map<unsigned long, User*> users;
public:
	USocial() {};
	~USocial();
	User* registerUser(std::string Username, bool bussiness = false);
	void removeUser(User* user);
	User* getUserById(unsigned long id);
};
#endif