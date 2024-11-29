#pragma once
#include <string>
#include "DeviceList.h"

class User
{
public:
	void init(const unsigned int id, const std::string username, const unsigned int age);

	void clear();

	unsigned int getID() const;
	const std::string& getUserName() const;
	unsigned int getAge() const;
	DevicesList& getDevices() const;

	void addDevice(const Device& newDevice);

	bool checkIfDevicesAreOn() const;

private:
	unsigned int _id;
	unsigned int _age;
	std::string _username;
	DevicesList* _device;
};