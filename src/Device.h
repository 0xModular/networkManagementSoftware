#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "ReferenceValidationMechanism.h"

class ReferenceValidationMechanism;

class Device{

	public:

		//public functions 

		//only use these methods for now
		Device(std::string mac, std::string IPv4, bool wiredConnection, std::string deviceName);
		~Device();
		std::string getIpv4(ReferenceValidationMechanism *r);
		std::string getMac(ReferenceValidationMechanism *r);
		bool getWired(ReferenceValidationMechanism *r);
		std::string getName(ReferenceValidationMechanism *r);
		

		Device(std::string IPv4, std::string IPv6, std::string deafaultGatway, std::string connectionType, std::vector<std::string> flags, std::vector<int> openPorts, bool staticIP, std::string mac);
		std::vector<std::string> setPrivacyFlags(std::vector<std::string> newFlags);
		void resetPrivacyFlags();
		void setDeviceDetails(std::string IPv4, std::string IPv6, std::string defaultGateway, std::vector<int> openPorts, bool staticIP);

	private:

		//private function
		void validateDeviceDetailInputs(std::string *IPv4, std::string *IPv6, std::string *defaultGateway, std::vector<int> *openPorts, bool *staticIP);

		//members
		std::string macAddress;
		std::string localIpv4;
		std::string localIpv6;
		std::string name;
		std::string defaultGateway;
		std::string connectionType;
		std::vector<std::string> privacyFlags;
		std::vector<int> openPorts;
		bool staticIp;
		bool limitedMembers;
		bool wired;
};





