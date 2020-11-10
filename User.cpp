#include "User.h"
#include "USocial.h"
#include <algorithm>

User::User(const std::string username, USocial* social_net, const unsigned long id) :
	_id(id), _name(username), _us(social_net) {
}

User::~User() {
	// Delete the users data from the system - Posts & Messages
	// Delete posts
	if (!_posts.empty()) {
		for (auto post_iterator = _posts.begin(); post_iterator != _posts.end(); ++post_iterator) {
			delete* post_iterator;
		}
	}

	// Delete messages
	if (!_receivedMsgs.empty()) {
		for (auto message_iterator = _receivedMsgs.begin(); message_iterator != _receivedMsgs.end(); ++message_iterator) {
			delete* message_iterator;
		}
	}
}

bool User::is_friend(const unsigned int id) {
	// A helper function to check if a given user id is in our friends list
	if (_friends.empty()) { return false; }
	if (std::find(_friends.begin(), _friends.end(), id) == _friends.end()) { return false; }
	return true;
}

unsigned long User::getId() {
	return _id;
}

std::string User::getName() {
	return std::string(_name);
}

void User::addFriend(User* new_friend) {
	// Check if the new friend is in this users friend list by his id
	// In case he is, raise an error
	// If he isn't, add the id to the friends list

	const unsigned int friend_id = new_friend->getId();

	if (is_friend(friend_id)) {
		throw in_friends_list;
	}
	_friends.push_back(friend_id);
}

void User::removeFriend(User* user) {
	const unsigned int del_id = user->getId();

	if (!is_friend(del_id)) {
		throw not_friend_error;
	}
	
	_friends.remove(del_id);
}

void User::post(std::string text) {
	Post* post = new Post(text);
	// Put the new post in the beginning of the posts list as it is the newest :)
	_posts.push_front(post);
}

void User::post(std::string text, Media* media) {
	Post* post = new Post(text, media);
	// Put the new post in the beginning of the posts list as it is the newest :)
	_posts.push_front(post);
}

std::list<Post*> User::getPosts() {
	return _posts;
}

void User::viewFriendsPosts() {
	// Iterate over the users friends list	
	for (std::list<unsigned long>::iterator id = _friends.begin(); id != _friends.end(); ++id)
	{
		// Get their user object from the USocial instance
		User* user = _us->getUserById(*id);

		std::list<Post*> posts = user->getPosts();
		std::cout << "\t" << (*user).getName() << " posts:" << std::endl;
		// Get the friends posts
		for (std::list<Post*>::iterator post = posts.begin(); post != posts.end(); ++post) {
			// Iterate and print their posts
			std::cout << "\t\t" << (*post)->getText() << std::endl;
			if ((*post)->getMedia() != NULL)
				(*post)->getMedia()->display();
		}
	}
}

void User::receiveMessage(Message* msg) {
	// Add the newest message to the top of the message list
	_receivedMsgs.push_front(msg);
}

void User::sendMessage(User* recipient, Message* msg) {
	// Check if the user is in our friends list and send a message if he is
	// Throw an exception if he is not.
	const unsigned int recipient_id = recipient->getId();
	if (is_friend(recipient_id)) { 
		recipient->receiveMessage(msg); 
	}
	else { 
		throw not_friend_error;
	}
}

void User::viewReceivedMessages() {
	// Iterate over the received messages and print them
	if (_receivedMsgs.empty()) {
		throw no_messages;
	}
	std::cout << "\t" << _name << "'s messages:" << std::endl;
	for (std::list<Message*>::iterator msg = _receivedMsgs.begin(); msg != _receivedMsgs.end(); ++msg) {
		std::cout << "\t\t" << (*msg)->getText() << std::endl;
	}
}