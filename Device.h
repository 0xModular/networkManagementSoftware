#include <string>

#ifndef DEVICE_H_
#define DEVICE_H_

class Device{

	public:
		Device::Device();
		Device::~Device();
		Device getDeviceDetails();
		Device setDeviceDetails();

		//protected functions
	protected:
		void validateDeviceDetailInputs();


		std::string localIpv4;
		std::string localIpv6;
		std::string defaultGateway;
		std::string connectionType;
		std::vector<std::string> privacyFlags;
		std::vector<int> openPorts;
		bool staticIp;
};

#endif





