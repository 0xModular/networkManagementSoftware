/*
 * Account.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Light
 */

#include <vector>
#include "Device.h"

#ifndef SRC_ACCOUNT_H_
#define SRC_ACCOUNT_H_

class Account{


	public:

		//public functions
		Account addAccount(); //add Account
		//Starts by calling contructor
		//check if Account exists

		Account removeAccount(); //remove Account, end with calling deconstructor
		//check if Account exists

		Account editAccount();

		Account linkDevice();
		Account unlinkDevice();

	//protected functions
	protected:

		void sendDeviceLinkNotifications();
		static Account getInfoFromDB(); //does not retieve password
		static Account addAccountToBD(); //encrypt details before sending
		static void checkIfAccountExists(); //encrypt details before sending


		Account linkDevice(Device d);
		Account overwriteAccountDetailsInDB(); //encrypt before sending
		Account resetPassword(); //never read password from db, certain entities may overwrite it


	//variables
		std::string type; //should not be changed after Account created
		std::string userName;
		std::vector<Device> linkedDevices;

		Account();
		~Account();


};




#endif /* SRC_ACCOUNT_H_ */
