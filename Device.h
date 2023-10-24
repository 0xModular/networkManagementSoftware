#ifndef FILES_DEVICE_H_
#define FILES_DEVICE_H_

#include <string>

class Device{

	public:
		Device::Device();
		Device::~Device();
		Device getDeviceDetails();
		Device setDeviceDetails();

		//protected functions
	protected:
		void validateDeviceDetailInputs();


		string localIpv4;
		string localIpv6;
		string defaultGateway;
		string connectionType;
		string[] privacyFlags;
		int[] openPorts;
		bool staticIp;
};

#endif





