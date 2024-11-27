#include <iostream>
#include <string> std::string
#include "Device.h"

// This Function Initialized The Device
// Input: The ID, The Device Type And The os
// Output: None
void Device::init(const unsigned int id, const DeviceType type, const std::string os)
{
	this->_id = id;
	this->_type = type;
	this->_os = os;
	this->_active = true;
}

// This Function Return The ID Of The Device
// Input: None
// Output: The ID Of The Device
unsigned int Device::getID() const
{
	return _id;
}

// This Function Return The Device's Type
// Input: None
// Output: The Device's Type
DeviceType Device::getType() const
{
	return _type;
}

// This Function Return The Device's OS
// Input: None
// Output: The Device's OS
std::string Device::getOS() const
{
	return _os;
}

// This Function Check If The Device Is Active Or Not
// Input: None
// Output: True Or False
bool Device::isActive() const
{
	return this->_active;
}

// This Function Make The Device Active
// Input: None
// Output: None
void Device::activate()
{
	this->_active = true;
}

// This Function Deactive The Device
// Input: None
// Output: None
void Device::deactivate()
{
	this->_active = false;
}