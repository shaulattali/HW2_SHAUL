#pragma once
#include <string>
#include "ProfileList.h"

class SocialNetwork
{
public:
	void init(std::string networkName, int minAge);
	void clear();

	std::string getNetworkName() const;
	std::string getWindowsDevices() const;
	int getMinAge() const;

	bool addProfile(Profile profile_to_add);

private:
	std::string networkName;
	int minAge;
	ProfileList* list;
};
