#ifndef SRC_ACCOUNT_H_
#define SRC_ACCOUNT_H_

#include <string>
#include <vector>

#include "Device.h"

class ReferenceValidationMechanism;

class Account{


	public:

		//public static methods
		//static Account addAccount(std::string name, std::string type, std::string category); //Creates a new account in the database.
		//static std::vector<Account> getManagableAccounts(ReferenceValidationMechanism *r); //Gets accounts that an admin account can manage.

		//public methods
		void removeAccount(ReferenceValidationMechanism *r); //Sends a request to the database to remove an account. First it checks if that account exists in the database using checkIfAccountExists.
		Account editAccount(ReferenceValidationMechanism *r);
		Account linkDevice(Device d, ReferenceValidationMechanism *r);
		Account unlinkDevice(Device d, ReferenceValidationMechanism *r);
		void getAccountDetails(std::string *name, std::string *type, std::string *category, std::vector<Device> *linkedDevices);

	private:

		//private static methods
		//static void EncryptOutgoingInfo(std::string *d);
		//static bool checkIfAccountExists();

		//private function
		bool sendDeviceLinkNotifications();
		void notifyAccountandDevice(Device d);
		Account overwriteAccountDetailsInDB(); 
		Account resetPassword(); 
		Account();
		~Account();


	//variables
		std::string type; 
		std::string userName;
		std::vector<Device> linkedDevices;
		std::string category; 

};




#endif /* SRC_ACCOUNT_H_ */
