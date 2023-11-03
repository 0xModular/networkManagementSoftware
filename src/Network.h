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

/*
Machine1 (10.0.2.4) at 08:00:27:ad:87:b3 [ether] om etho0
Machine2 (10.0.2.5) at 08:00:27:27:d6:b7 [ether] om etho0
_gateway (10.0.2.1) at 08:00:27:65:r5:89 [ether] om etho0

Machine ([a-zA-Z0-9]+)\s
Ip \(([0-9]+\.[0-9]+\.[0-9]+\.[0-9]+)\)
([_a-zA-Z0-9]+)\s\(([0-9]+\.[0-9]+\.[0-9]+\.[0-9]+)\)\sat\s([0-9a-fA-F]+:[0-9a-fA-F]+:[0-9a-fA-F]+:[0-9a-fA-F]+:[0-9a-fA-F]+:[0-9a-fA-F]+)\s\[([a-zA-Z0-9]+)\]\son\s([a-zA-Z0-9]+)\n

*/