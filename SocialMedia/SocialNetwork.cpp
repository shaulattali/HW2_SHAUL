#include "SocialNetwork.h"

// This Function Initialized The Network Name And The Minimum Age
// Input: The Network Name And The Minimum Age
// Output: None
void SocialNetwork::init(std::string networkName, int minAge)
{
	this->networkName = networkName;
	this->minAge = minAge;
	this->list = new ProfileList();
	list->init();
}

// This Function Clear The Object And Delete The Memory 
// Input: None
// Output: None
void SocialNetwork::clear()
{
	delete this->list;
}

// This Function Return The Network Name
// Input: None
// Output: The Network Name
std::string SocialNetwork::getNetworkName() const
{
	return this->networkName;
}

// This Function Return The Windows Devices
// Input None
// Output: The Windows Devices
std::string SocialNetwork::getWindowsDevices() const
{
	ProfileNode* current = list->get_first();
	std::string finalResult = "";

    //Until the end
    while (current != nullptr)
    {
        //The owner data
        Profile profile = current->get_data();
        User user = profile.getOwner();

        //The user's device
        DevicesList devices = user.getDevices();
        DeviceNode* currentDeviceNode = devices.get_first();


        while (currentDeviceNode != nullptr)
        {
            Device device = currentDeviceNode->get_data();

            //Check if the device is one of the WINDOWS type.. (like 7, 10 or 11)
            std::string os = device.getOS();
            if (os == WINDOWS10 || os == WINDOWS11 || os == WINDOWS7)
            {
                if (!finalResult.empty())
                {
                    finalResult += ", ";
                }
                finalResult += "[" + std::to_string(device.getID()) + ", " + os + "]";
            }

            currentDeviceNode = currentDeviceNode->get_next();
        }

        current = current->get_next();
    }

    // Return the final result
    return finalResult;
}

// This Function Return The Minimum Age
// Input: None
// Output: The Minimum Age
int SocialNetwork::getMinAge() const
{
	return this->minAge;
}

// This Function Add Profile And Checck If The User's Age Is
// Less Than The Minimum Age
// Input: Profile To Add
// Output: True Or False (By The Age Verification)
bool SocialNetwork::addProfile(Profile profile_to_add)
{
	//Checks if the user's age is less than the minimum age
	if (profile_to_add.getOwner().getAge() < minAge)
	{
		return false;
	}

	//If not - just add it
	this->list->add(profile_to_add);

	return true;
}
