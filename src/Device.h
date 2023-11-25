/*
 * Device.h
 * Created on: Oct 24, 2023
 *
 * Author:
 */

#pragma once
#include <iostream>
#include <cstring>
#include <sstream>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <vector>
#include "ReferenceValidationMechanism.h"
#include "Connection.h"

class Connection;
class ReferenceValidationMechanism;

class Device{

	public:

		//working 
		Device(std::string mac, std::string IPv4, bool wiredConnection, std::string deviceName); //Constructor
		std::string GetIpv4(ReferenceValidationMechanism *r);
		std::string GetMac(ReferenceValidationMechanism *r);
		bool GetWired(ReferenceValidationMechanism *r);
		std::string GetName(ReferenceValidationMechanism *r);
		std::vector<Connection> GetConnectionVector();
		bool ConnectToUpdateDeviceDetails(ReferenceValidationMechanism *r);
		bool GetDeviceConnections(ReferenceValidationMechanism *r);
		bool ChangeStaticIp(std::string newIP, ReferenceValidationMechanism *r);
		bool ChangeToDHCP(ReferenceValidationMechanism *r);
		int PingAnotherDevice(Device d, ReferenceValidationMechanism *r);
		~Device(); //Destructor
		
		
		//ignore for now
		std::vector<std::string> SetPrivacyFlags(std::vector<std::string> newFlags);	
		void ResetPrivacyFlags();
		Device(std::string IPv4, std::string IPv6, std::string deafaultGatway, std::string connectionType, std::vector<std::string> flags, std::vector<int> openPorts, bool staticIP, std::string mac);
		
		
	private:

		//working
		std::string SendMessageToDeviceAndGetResponse(std::string message, std::string networyCategory);

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
		std::vector<Connection> connections;
		bool staticIp;
		bool limitedMembers;
		bool wired;

};