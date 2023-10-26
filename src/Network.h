#ifndef SRC_NETWORK_H_
#define SRC_NETWORK_H_

#include "Account.h"

class Network{

	public:

		//public methods
		Network(); //Calls getDevices, getGeneralNetworkDetails, and getConnections to get information needed for  the current network.
		void refresh(); //get updated information for the network

	private:

		//private methods
		void getDevices();
		void getGeneralNetworkDetails();
		void getConnections();
		void editDevices(ReferenceValidationMechanism *r);
		void editGeneralNetworkDetails(ReferenceValidationMechanism *r);
		void editConnections(ReferenceValidationMechanism *r);

		//networkdetailsvalidation

		//members
		std::string gateway;
		long long timeSinceRefresh();
		std::vector<Device> deviceList;
		std::vector<Device> connectionList;
};



#endif /* SRC_NETWORK_H_ */
