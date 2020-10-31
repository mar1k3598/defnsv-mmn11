#ifndef USOCIAL_H_
#define USOCIAL_H_

#ifndef USER_H_
#define USER_H_

#ifndef USOCIAL_H_
#endif
#pragma once
#include "User.h"
#include <string>

#endif
using namespace std;

class USocial {
	User* users;
public:
	User* registerUser(string Username, bool bussiness);
	void removeUser(User user);
	User* getUserById(unsigned long id);
};

#endif