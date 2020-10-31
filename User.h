#pragma once
#include "Message.h"
#include "Post.h"
#include "USocial.h"

#include <list>
#include <string>
#include <iostream>

using namespace std;

class User {
	USocial* us;
	unsigned long id;
	string name;
	list<unsigned long> friends;
	list<Post*> posts;
	list<Message*> receivedMsgs;
private:
	User();
	~User();
public:
	unsigned long getId();
	string getName();
	void addFriend(User* user);
	void removeFriend(User* user);
	void post(string text);
	void post(string text, Media* attachment);
	list<Post*> getPosts();
	void viewFriendsPosts();
	void reveiceMessage(Message* msg);
	void sendMessage(User* recipient, Message* msg);
	void viewReceivedMessages();
};