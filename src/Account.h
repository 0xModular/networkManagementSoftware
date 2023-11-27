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
#include "Log.h"
#include "ReferenceValidationMechanism.h"
#include <mysql_connection.h>
#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include "DatabaseConnection.h"

class Device;
class ReferenceValidationMechanism;

class Account{

	public:


		//finished and ready
		static int CreateNewAccountInDB(std::string name, std::string password1, std::string password2, std::string type, std::string cat, Account *&a);
		std::string GetAccountType();
		std::string GetAccountName();
		std::string GetAccountCat();
		Account(std::string name, std::string t, std::string cat); //Constructor
		static std::vector<Account> GetManagableAccounts(ReferenceValidationMechanism *r); //Gets accounts that an admin account can manage.
		bool RemoveAccount(ReferenceValidationMechanism *r); 
		bool EditAccountName(std::string newName, ReferenceValidationMechanism *r);
		~Account(); //Destructor
		
		//wip
		Account LinkDevice(Device d, ReferenceValidationMechanism *r);
		Account UnlinkDevice(Device d, ReferenceValidationMechanism *r);

	private:

		//wip
		bool SendDeviceLinkNotifications();
		bool NotifyAccount(std::string message, Account a, ReferenceValidationMechanism *r);
		Account ResetPassword(); 



		//variables
		std::string type; 
		std::string userName;
		std::vector<Device> linkedDevices;
		std::string category; 

};




