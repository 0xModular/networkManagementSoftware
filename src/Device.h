#include <string>

#ifndef SRC_DEVICE_H_
#define SRC_DEVICE_H_

class Device{

	public:

		//public functions
		Device(std::string IPv4, std::string IPv6, std::string deafaultGatway, std::string connectionType, std::vector<std::string> flags, std::vector<int> openPorts, bool staticIP, std::string mac);
		~Device();
		std::vector<string> setPrivacyFlags(std::vector<string> newFlags)
		void resetPrivacyFlags();
		void setDeviceDetails(std::string IPv4, std::string IPv6, std::string defaultGateway, std::vector<int> openPorts, bool staticIP);

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
};

#endif





