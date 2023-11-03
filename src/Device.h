#include <string>
#include <vector>

class ReferenceValidationMechanism;

#ifndef SRC_DEVICE_H_
#define SRC_DEVICE_H_

#include "ReferenceValidationMechanism.h"

class Device{

	public:

		//public functions ipv4, ipv6, gateway, wired/wireless, flags, ports, static/dynamic, mac
		Device(std::string IPv4, std::string IPv6, std::string deafaultGatway, std::string connectionType, std::vector<std::string> flags, std::vector<int> openPorts, bool staticIP, std::string mac);
		Device(std::string IPv4, bool staticIP, std::string mac);
		~Device();
		std::vector<std::string> setPrivacyFlags(std::vector<std::string> newFlags);
		void resetPrivacyFlags();
		void setDeviceDetails(std::string IPv4, std::string IPv6, std::string defaultGateway, std::vector<int> openPorts, bool staticIP);
		std::string getIpv4(ReferenceValidationMechanism *r);
		std::string getMac(ReferenceValidationMechanism *r);
		bool getIsStaticIp(ReferenceValidationMechanism *r);

	private:

		//private function
		void validateDeviceDetailInputs(std::string *IPv4, std::string *IPv6, std::string *defaultGateway, std::vector<int> *openPorts, bool *staticIP);

		//members
		std::string localIpv4;
		std::string localIpv6;
		std::string macAddress;
		std::string defaultGateway;
		std::string connectionType;
		std::vector<std::string> privacyFlags;
		std::vector<int> openPorts;
		bool staticIp;
		bool limitedMembers;
};

#endif




