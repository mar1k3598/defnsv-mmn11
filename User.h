#pragma once
#ifndef _USER_H
#define _USER_H
#include <list>
#include <string>
#include <iostream>
#include <exception>

#include "Message.h"
#include "Post.h"

class USocial;
class User {
	friend class USocial;
protected:
	class myexception : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "Error: The user is in your friends list!";
		}
	} not_friend_exception;
	USocial* _us;
	const unsigned long _id;
	std::string _name;
	std::list<unsigned long> _friends;
	std::list<Post*> _posts;
	std::list<Message*> _receivedMsgs;
	User(const std::string username, USocial* social_net, const unsigned long id);
	~User();
	bool is_friend(const unsigned int id);
public:
	unsigned long getId();
	std::string getName();
	void addFriend(User* user);
	void removeFriend(User* user);
	void post(std::string text);
	void post(std::string text, Media* attachment);
	std::list<Post*> getPosts();
	void viewFriendsPosts();
	void receiveMessage(Message* msg);
	virtual void sendMessage(User* recipient, Message* msg);
	void viewReceivedMessages();
};
#endif