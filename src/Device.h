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
#include <unordered_set>
#include "ReferenceValidationMechanism.h"
#include "Connection.h"

class Connection;
class ReferenceValidationMechanism;

class Device{

	public:

		//working \/\/\/
		Device(std::string mac, std::string IPv4, bool wiredConnection, std::string deviceName); //Constructor
		Device(std::string mac, std::string IPv4, bool wiredConnection, std::string deviceName, int x, int y); //Constructor
		~Device(); //Destructor

		bool ConnectToUpdateDeviceDetails(ReferenceValidationMechanism *r);
		bool ChangeStaticIp(std::string newIP, ReferenceValidationMechanism *r); //this will eventualy return int. -1 is cant connect, 0 is success, 1 is invalid input.
		bool ChangeToDHCP(ReferenceValidationMechanism *r);
		int PingAnotherDevice(Device d, ReferenceValidationMechanism *r);
		int PingAnotherDevice(std::string, ReferenceValidationMechanism *r);
		bool TerminateConnection(Connection c, ReferenceValidationMechanism *r);
		bool TerminateConnection(int pid, ReferenceValidationMechanism *r);
		bool GetDeviceConnections(ReferenceValidationMechanism *r);
		

		//getters
		std::string GetIpv4();
		std::string GetMac();
		bool GetWired();
		std::string GetName();
		std::string GetIpv6(); //!!! WILL NOT RETURN ANYTHING IF ConnectToUpdateDeviceDetails HASNT COMPLETED SUCCESFULLY YET !!!
		std::string GetDefaultGateway(); //!!! WILL NOT RETURN ANYTHING IF ConnectToUpdateDeviceDetails HASNT COMPLETED SUCCESFULLY YET !!!
		bool GetIsStaticIp(); //!!! WILL NOT RETURN ANYTHING IF ConnectToUpdateDeviceDetails HASNT COMPLETED SUCCESFULLY YET !!!
		std::vector<Connection> GetConnectionVector(); //!!! WILL RETURN EMPTY VECTOR IF GetDeviceConnections HASNT COMPLETED SUCCESFULLY YET !!!
		int GetX();
		int GetY();

		//setters
		void SetX(int x);
		void SetY(int y);


		//ignore for now \/\/\/
		std::vector<std::string> SetPrivacyFlags(std::vector<std::string> newFlags);	
		void ResetPrivacyFlags();
		
	private:

		//working
		std::string SendMessageToDeviceAndGetResponse(std::string message, std::string networyCategory);
		static int NewRandomNumber();
		//ignore for now
		
		//members
		std::string macAddress;
		std::string localIpv4;
		std::string localIpv6;
		std::string name;
		std::string defaultGateway;
		std::string adapter;
		std::vector<std::string> privacyFlags;
		std::vector<Connection> connections;
		bool staticIp;
		bool limitedMembers;
		bool wired;
		int posX;
		int posY;

};
