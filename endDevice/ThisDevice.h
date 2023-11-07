#include <string>
#include <vector>
#include "Connection.h"

#ifndef SRC_THISDEVICE_H_
#define SRC_THISDEVICE_H_

class ThisDevice{

	public:

		void getAllMembers();
		std::string getDefaultAdapater();
		std::vector<Connection> getConnections();

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
		bool limitedMembers;
		bool wired;
};

#endif




