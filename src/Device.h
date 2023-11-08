/*
 * Device.h
 * Created on: Oct 24, 2023
 *
 * Author:
 */

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
		Device(std::string mac, std::string IPv4, bool wiredConnection, std::string deviceName); //Constructors
		Device(std::string IPv4, std::string IPv6, std::string deafaultGatway, std::string connectionType, std::vector<std::string> flags, std::vector<int> openPorts, bool staticIP, std::string mac);
		~Device(); //Destructor
		
		std::string GetIpv4(ReferenceValidationMechanism *r);
		std::string GetMac(ReferenceValidationMechanism *r);
		
		bool GetWired(ReferenceValidationMechanism *r);
		std::string GetName(ReferenceValidationMechanism *r);
		
		std::vector<std::string> SetPrivacyFlags(std::vector<std::string> newFlags);	
		void ResetPrivacyFlags();

		void SetDeviceDetails(std::string IPv4, std::string IPv6, std::string defaultGateway, std::vector<int> openPorts, bool staticIP);

	private:

		//private function
		void ValidateDeviceDetailInputs(std::string *IPv4, std::string *IPv6, std::string *defaultGateway, std::vector<int> *openPorts, bool *staticIP);

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
