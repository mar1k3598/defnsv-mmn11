#include "USocial.h"
#include "User.h"

#include <exception>
#include <iostream>


int main()
{
	USocial us;

	User* u1 = us.registerUser("Liron");
	User* u2 = us.registerUser("Yahav");
	User* u3 = us.registerUser("Shachaf");
	User* u4 = us.registerUser("Tsur", true);
	User* u5 = us.registerUser("Elit");

	u1->post("Hello world!");
	u2->post("I'm having a great time here :)", new Audio());
	u3->post("This is awesome!", new Photo());

	// Try printing users messages with an empty message box
	try {
		u5->viewReceivedMessages(); 
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	u5->addFriend(u1);
	
	// check the addition of an existing user to ones friends list
	try {
		u5->addFriend(u1);
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	u5->addFriend(u2);
	// check the removal of a non friend user
	try {
		u5->removeFriend(u4);// check the addition of an existing user to ones friends list
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}


	u5->viewFriendsPosts();	// should see only u1, u2 s' posts

	u4->sendMessage(u5, new Message("Buy Falafel!"));
	u5->viewReceivedMessages();
	
	// Try to send a message to a user who is not in our friends list
	try
	{
		u3->sendMessage(u5, new Message("All your base are belong to us"));
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try {
		u5->viewReceivedMessages();
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	u3->addFriend(u5);

	// Remove a friend not in a users friends list
	try {
		u3->removeFriend(u4);
	}
	catch (const std::exception & e)
	{
		std::cout  << e.what() << std::endl;
	}
	u3->sendMessage(u5, new Message("All your base are belong to us"));
	u5->viewReceivedMessages();

 	return 0;
 }