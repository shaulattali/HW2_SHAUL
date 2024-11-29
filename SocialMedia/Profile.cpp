#include <iostream>
#include <string> std::string
#include "Profile.h"
#include "UserList.h"

// This Function Initialized The User's Profile
// Input: The Owner
// Output: None
void Profile::init(User owner)
{
	this->_owner = owner;

	// We Need To Do Memory Stuff (new)
	this->_page = new Page();
	this->_page->init();

	this->_friendsList = new UserList();
	this->_friendsList->init();
}

// This Function Clear The Objects And Delete The Memory 
// Input: None
// Output: None
void Profile::clear()
{
	_friendsList->clear();

	//Same thing but with (delete) ;D
	delete _page;
	delete _friendsList;
}

// This Function Return The Owner Of The Profile
// Input: None
// Output: The Owner
User Profile::getOwner() const
{
	return _owner;
}

// This Function Return String Of All The User's Page (By Format)
// Input: None
// Output: String Of All The User's Page (By Format)
std::string Profile::getPage() const
{
	std::string border = "*******************\n";
	border += "*******************";

	std::string statusLine = "Status: " + _page->getStatus() + "\n";
	std::string posts = _page->getPosts();

	//Combine together
	std::string output = statusLine + border + "\n" + posts;

	return output;
}

// This Function Return Strings Of The User's Friends (Like --> shaul,itay,shay,noam)
// Input: None
// Output: Strings Of The User's Friends (By Format)
std::string Profile::getFriends() const
{
	//We check if the FriendsList is empty
	if (!_friendsList || !_friendsList->get_first())
	{
		return "";
	}

	std::string friendsString;
	UserNode* current = _friendsList->get_first();

	//Until the end of the list
	while (current != nullptr)
	{
		friendsString += current->get_data().getUserName();

		//Adding the , (like I want --> shaul,itay,shay,noam)
		if (current->get_next() != nullptr)
		{
			friendsString += ",";
		}

		current = current->get_next();
	}
	return friendsString;
}

// This Function Return String Of The User's Friends
// (But Their Username Is The Same Length As The Owner Of The Profile)
// Input: None
// Output: String Of The User's Friends
//         (But Their Username Is The Same Length As The Owner Of The Profile)
std::string Profile::getFriendsWithSameNameLength() const
{
	//We check if the FriendsList is empty
	if (!_friendsList || !_friendsList->get_first())
	{
		return "";
	}

	//Flag "isFirstFriend"
	bool isFirstFriend = true; 

	//Sorry about the long name (it's just for me to understand...)
	std::string friendsStringWithSameNameLength = "";
	std::string friendUsername = "";

	UserNode* current = _friendsList->get_first();

	//Until the end
	while (current != nullptr)
	{
		friendUsername = current->get_data().getUserName();

		//Check if their length equals
		if (friendUsername.length() == _owner.getUserName().length())
		{
			if (!isFirstFriend)
			{
				friendsStringWithSameNameLength += ",";
			}

			friendsStringWithSameNameLength += friendUsername;

			//Reset My Flag
			isFirstFriend = false;
		}
		current = current->get_next();
	}
	return friendsStringWithSameNameLength;
}

// This Function Change The Status To The New Status
// Input: The New Status
// Output: None
void Profile::setStatus(std::string new_status)
{
	_page->setStatus(new_status);
}

// This Function Add Post To The User's Profile Page
// Input: The Post
// Output: None
void Profile::addPostToProfilePage(std::string post)
{
	_page->addLineToPosts(post);
}

// This Function Add Friend To The User's Friends List
// Input: The Friend That The User Want To Add
// Output None
void Profile::addFriend(User friend_to_add)
{
	_friendsList->add(friend_to_add);
}