#pragma once
#include <string>
#include "Page.h"
#include "UserList.h"

class Profile
{
public:
	void init(User owner);
	void clear();

	User getOwner() const;
	std::string getPage() const;
	std::string getFriends() const;
	std::string getFriendsWithSameNameLength() const;

	void setStatus(std::string new_status);

	void addPostToProfilePage(std::string post);
	void addFriend(User friend_to_add);


private:
	User _owner;
	Page* _page;
	UserList* _friendsList;
};