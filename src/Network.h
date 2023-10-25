/*
 * Network.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Light
 */

#ifndef SRC_NETWORK_H_
#define SRC_NETWORK_H_

#include "Account.h"

class Network{

	public:

		Network();
		void refresh();

	private:

		void getDevices();
		void getGeneralNetworkDetails();
		void getConnections();

		void editDevices();
		void editGeneralNetworkDetails();
		void editConnections();

		long long timeSinceRefresh();
		std::vector<Device> deviceList;
		std::vector<Device> connectionList;
};



#endif /* SRC_NETWORK_H_ */
