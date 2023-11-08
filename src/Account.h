/*
 * Account.h
 * Created on: Oct 24, 2023
 *
 * Author:
 */ 

#pragma once
#include <string>
#include <vector>
#include "Device.h"
#include "ReferenceValidationMechanism.h"

class Device;
class ReferenceValidationMechanism;

class Account{

	public:

		//public static methods
		static std::vector<Account> GetManagableAccounts(ReferenceValidationMechanism *r); //Gets accounts that an admin account can manage.

		//public methods
		void RemoveAccount(ReferenceValidationMechanism *r); //Sends a request to the database to remove an account. First it checks if that account exists in the database using checkIfAccountExists.
		Account EditAccount(ReferenceValidationMechanism *r);
		Account LinkDevice(Device d, ReferenceValidationMechanism *r);
		Account UnlinkDevice(Device d, ReferenceValidationMechanism *r);
		void GetAccountDetails(std::string *name, std::string *type, std::string *category, std::vector<Device> *linkedDevices);
		std::string GetAccountType();

		Account(std::string *name, std::string *t, std::string *cat); //Constructors
		Account();
		~Account(); //Destructor

	private:

		//private static methods
		static void EncryptOutgoingInfo(std::string *d);
		static bool CheckIfAccountExists();

		//private function
		bool SendDeviceLinkNotifications();
		void NotifyAccountandDevice(Device d);
		Account OverwriteAccountDetailsInDB(); 
		Account ResetPassword(); 



		//variables
		std::string type; 
		std::string userName;
		std::vector<Device> linkedDevices;
		std::string category; 

};




