#ifndef SRC_NETWORK_H_
#define SRC_NETWORK_H_

#include <string>
#include <vector>

#include "Device.h"
class Device;

class Network{

	public:

		//public methods
		Network(); //Calls getDevices, getGeneralNetworkDetails, and getConnections to get information needed for  the current network.
		void refresh(ReferenceValidationMechanism *r); //get updated information for the network
		std::vector<Device> getDeviceList(ReferenceValidationMechanism *r);

	private:

		//private methods
		void getDevices();
		void getGeneralNetworkDetails();
		void getConnections();
		void editDevices(Device d, std::string requestType, std::string AdditionalData);
		void editGeneralNetworkDetails(ReferenceValidationMechanism *r);
		void editConnections(ReferenceValidationMechanism *r);
		void validateDeviceDetailInputs(std::string gate, std::string DNS);

		//networkdetailsvalidation

		//members
		std::string gateway;
		std::string defaultDNS;
		long long timeSinceRefresh;
		std::vector<Device> deviceList;
		std::vector<Device> connectionList;
};



#endif /* SRC_NETWORK_H_ */