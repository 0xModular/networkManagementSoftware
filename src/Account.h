/*
 * Account.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Light
 */

#include <vector>
#include "src/Device.h"
#include "src/ReferenceValidationMechanism.h"

#ifndef SRC_ACCOUNT_H_
#define SRC_ACCOUNT_H_

class Account{


	public:

		//public static methods
		static Account addAccount(std::string name, std::string type, std::string category); //add Account
		static vector<Account> getManagableAccounts(ReferenceValidationMechanism *r) //gets accounts that an admin account can manage

		//public methods
		void removeAccount(ReferenceValidationMechanism *r);
		Account editAccount(ReferenceValidationMechanism *r);
		Account linkDevice(Device d, ReferenceValidationMechanism *r);
		Account unlinkDevice(Device d, ReferenceValidationMechanism *r);
		void getAccountDetails(std::string *name, std::string *type, std::string *category, std::vector<Device> *linkedDevices);
	private:

		//private static methods
		static void EncryptOutgoingInfo(std::string *d); //encrypt details before sending
		static bool checkIfAccountExists(); //encrypt details before sending

		//private function
		bool sendDeviceLinkNotifications();

		Account overwriteAccountDetailsInDB(); //encrypt before sending
		Account resetPassword(); //never read password from db, certain entities may overwrite it


	//variables
		std::string type; //should not be changed after Account created
		std::string userName;
		std::vector<Device> linkedDevices;
		std::string category; //should not be changed after Account created

		Account();
		~Account();


};




#endif /* SRC_ACCOUNT_H_ */
