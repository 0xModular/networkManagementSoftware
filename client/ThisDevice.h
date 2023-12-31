/*
 * ThisDevice.h
 * Created on: Nov 7, 2023
 *
 * Author: Layne
 */

#pragma once
#include <string>
#include <vector>

#include "Connection.h"

class ThisDevice{

	public:

		bool setStaticIP(std::string newIp);
		ThisDevice();
		bool UpdateAllMembers(std::string adapter);
		std::string GetDefaultAdapater();
		std::vector<Connection> GetConnections();
		std::string GetAllMembers();
		std::string ConnectionVectorToString();

	private:

		//members
	    std::string defaultAdapter;
		std::string macAddress;
		std::string localIpv4;
		std::string localIpv6;
		std::string name;
		std::string defaultGateway;
		std::vector<std::string> privacyFlags;
		std::vector<Connection> ports;
		bool staticIp;

};
