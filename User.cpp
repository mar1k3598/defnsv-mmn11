#include "User.h"
#include <algorithm>

unsigned long User::getId()
{
	// Return the users ID number
	return User::id;
}

string User::getName()
{
	return string(User::name);
}

void User::addFriend(User* user)
{

	//User::friends.insert(user->getId());
}

void User::post(string text) {
	Post* post = new Post(text);
	// Put the new post in the beginning of the posts list as it is the newest :)
	User::posts.push_front(post);
}

void User::post(string text, Media* media) {
	Post* post = new Post(text, media);
	// Put the new post in the beginning of the posts list as it is the newest :)
	User::posts.push_front(post);
}

list<Post*> User::getPosts() {
	return User::posts;
}

void User::viewFriendsPosts() {
	// Iterate over the users friends list	
	for (std::list<unsigned long>::iterator id = User::friends.begin(); id != User::friends.end(); ++id)
	{
		// Get their user object from the USocial instance
		User* user = User::us->getUserById(*id);

		cout << (*user).getName() << " posts:" << endl;
		// Get the friends posts
		std::list<Post*> posts = user->getPosts();
		for (std::list<Post*>::iterator post = posts.begin(); post != posts.end(); ++post) {
			// Iterate and print their posts
			cout << (*post)->getText << endl;
			cout << (*post)->getMedia << endl;
		}
	}
}