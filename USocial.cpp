#include "USocial.h"
#include "User.h"
#include "BusinessUser.h"

typedef uint32_t u32;

User* USocial::registerUser(std::string username, bool bussiness) {
	User* new_user;
	uint32_t new_id;
	bool user_exists = true;

	// Generate new pseudo random unsigned long ID for the user
	srand(time(NULL));
	while (user_exists) {
		new_id = ((u32)rand() << 17 ^ (u32)rand() << 2 ^ (u32)rand() >> 13) % ULONG_MAX; 
		if (users.find(new_id) == users.end() || users.empty()) { user_exists = false; }
	}

	// Create a new user object [business or regular]
	if (bussiness) {
		new_user = new BusinessUser(username, this, new_id);
	}
	else {
		new_user = new User(username, this, new_id);
	}

	// Add the newly created user to the users map
	users[new_id] = new_user;

	return new_user;
}

void USocial::removeUser(User* user) {
	// Remove a user from this social network, if not found raise an error
	auto users_iterator = users.begin();

	for (users_iterator; users_iterator != users.end(); ++users_iterator) {
		if (users_iterator->second == user) {
			users.erase(users_iterator->first);
			delete user;
		}
	}
	
	if (users_iterator == users.end()) {
		// Check if the user was not found in the social network, if so throw an exception
		throw "No such user in the social network!";
	}
}

User* USocial::getUserById(unsigned long id) {
	// Get the ptr to the User instance by a given user identifier
	std::map<unsigned long, User*>::iterator users_iterator = users.find(id);

	if (users_iterator == users.end())
		// If the user exists throw an error to the caller.
		throw "No user with such ID!";

	return users_iterator->second;
}

USocial::~USocial() {
	for (auto users_iterator = users.begin(); users_iterator != users.end(); ++users_iterator) {
 		delete users_iterator->second;
	}
	users.clear();
}