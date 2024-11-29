#include <iostream>
#include <string> std::string
#include "Page.h"


// This Function Initialized The User's Page
// Input: None
// Output: None
void Page::init()
{
	this->_status = "";
	this->_post = "";
}

// This Function Return The Posts Of The User
// Input: None
// Output: The Posts Of The User
std::string Page::getPosts() const
{
	return _post;
}

// This Function Return The Status Of The User
// Input: None
// Output: The Status Of The User
std::string Page::getStatus() const
{
	return _status;
}

// This Function Clear All The User's Page
// Input: None
// Output: None
void Page::clearPage()
{
	this->_post = "";
}

// This Function Change The Status
// Input: The Status
// Output: None
void Page::setStatus(std::string status)
{
	this->_status = status;
}

// This Function Add New Line To The User's Posts
// Input: The New Line
// Output: None
void Page::addLineToPosts(std::string new_line)
{
	// I'm adding a new line (if there are already posts)
	if (!_post.empty())
	{
		_post += "\n";
	}
	_post += new_line;
}