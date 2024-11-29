#include <iostream>
#include <string> std::string
#include "User.h"

// This Function Initialized The User's Information
// Input: The ID, The Username And The age
// Output: None
void User::init(const unsigned int id, const std::string username, const unsigned int age)
{
	this->_id = id;
	this->_username = username;
	this->_age = age;

	// The Device List:
	this->_device = new DevicesList();
	this->_device->init();
}

// This Function Clear The Object And Delete The Memory 
// Input: None
// Output: None
void User::clear()
{
	delete _device;
	_device = nullptr;
}

// This Function Return The ID Of The User
// Input: None
// Output: The ID Of The User
unsigned int User::getID() const
{
	return _id;
}

// This Function Return The Username Of The User
// Input: None
// Output: The Username Of The User
const std::string& User::getUserName() const
{
	return _username;
}

// This Function Return The Age Of The User
// Input: None
// Output: The Age Of The User
unsigned int User::getAge() const
{
	return _age;
}

// This Function Return The Age Of The User
// Input: None
// Output: The Reference To The Devices List Of The User
DevicesList& User::getDevices() const
{
	return *_device;
}

// This Function Add A New Device
// Input: Reference To New Device
// Output: None
void User::addDevice(const Device& newDevice)
{
	_device->add(newDevice);
}

// This Function Check If The Devices Are On
// Input: None
// Output: True Or False
bool User::checkIfDevicesAreOn() const
{
	DeviceNode* check = _device->get_first();

	while (check != nullptr)
	{
		if (!check->get_data().isActive())
		{
			return false;
		}

		check = check->get_next();
	}

	return true;
}