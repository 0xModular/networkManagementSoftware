/*
 * Device.h
 * Created on: Oct 24, 2023
 *
 * Author: Layne
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

		//constructors and deconstructor     Use AddNewDevice in Network for manually adding devices
		Device(std::string mac, std::string IPv4, bool wiredConnection, std::string deviceName); 
		Device(std::string mac, std::string IPv4, bool wiredConnection, std::string deviceName, bool on); 
		Device(std::string mac, std::string IPv4, bool wiredConnection, std::string deviceName, int x, int y); 
		Device(std::string mac, std::string IPv4, bool wiredConnection, std::string deviceName, int x, int y, bool on);
		~Device(); 

		//usable for end devices that are running the Network Manager background process. Bool false if task failed
		bool RetrieveMoreDeviceDetails(ReferenceValidationMechanism *r);
		bool ChangeStaticIp(std::string newIP, ReferenceValidationMechanism *r);
		bool ChangeToDHCP(ReferenceValidationMechanism *r);
		bool TerminateConnection(Connection c, ReferenceValidationMechanism *r);
		bool TerminateConnection(int pid, ReferenceValidationMechanism *r);
		bool RetrieveDeviceConnections(ReferenceValidationMechanism *r);
		//-1 means cant connect, otherwise it returns the average RTT in milliseconds
		int PingAnotherDevice(Device d, ReferenceValidationMechanism *r); 
		int PingAnotherDevice(std::string, ReferenceValidationMechanism *r);

		//getters
		std::string GetIpv4();
		std::string GetMac();
		bool GetWired();
		std::string GetName();
		std::string GetIpv6(); //!!! WILL NOT RETURN ANYTHING IF RetrieveMoreDeviceDetails HASNT COMPLETED SUCCESFULLY YET !!!
		std::string GetDefaultGateway(); //!!! WILL NOT RETURN ANYTHING IF RetrieveMoreDeviceDetails HASNT COMPLETED SUCCESFULLY YET !!!
		bool GetIsStaticIp(); //!!! WILL NOT RETURN ANYTHING IF RetrieveMoreDeviceDetails HASNT COMPLETED SUCCESFULLY YET !!!
		std::vector<Connection> GetConnectionVector(); //!!! WILL RETURN EMPTY VECTOR IF RetrieveDeviceConnections HASNT COMPLETED SUCCESFULLY YET !!!
		int GetX();
		int GetY();
		bool GetOnlineStatus();

		//setters
		void SetX(int x);
		void SetY(int y);
		void SetOnlineStatus(bool on);


		//ignore for now \/\/\/
		std::vector<std::string> SetPrivacyFlags(std::vector<std::string> newFlags);	
		void ResetPrivacyFlags();
		
	private:

		//working
		std::string SendMessageToDeviceAndGetResponse(std::string message, std::string networyCategory);
		static int NewRandomNumber();
		
		//members
		std::string macAddress;
		std::string localIpv4;
		std::string localIpv6;
		std::string name;
		std::string defaultGateway;
		std::vector<Connection> connections;
		bool staticIp;
		bool wired;
		bool online;
		int posX;
		int posY;

		//dont worry about
		bool limitedMembers;
		std::string adapter;
		std::vector<std::string> privacyFlags;

};
