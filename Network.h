/*
 * Network.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Light
 */

#ifndef FILES_NETWORK_H_
#define FILES_NETWORK_H_

#include "Account.h"

class Network{

	public:

		static void displayNetwork(Account a);

	private:

		void getDevices();
		void getGeneralNetworkDetails();
};



#endif /* FILES_NETWORK_H_ */
