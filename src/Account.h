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

		
		
		//wip
		static std::vector<Account> GetManagableAccounts(ReferenceValidationMechanism *r); //Gets accounts that an admin account can manage.
		void RemoveAccount(ReferenceValidationMechanism *r); 
		Account EditAccount(ReferenceValidationMechanism *r);
		Account LinkDevice(Device d, ReferenceValidationMechanism *r);
		Account UnlinkDevice(Device d, ReferenceValidationMechanism *r);
		Account();
		~Account(); //Destructor

	private:

		//wip
		bool SendDeviceLinkNotifications();
		void NotifyAccountandDevice(Device d);
		Account ResetPassword(); 



		//variables
		std::string type; 
		std::string userName;
		std::vector<Device> linkedDevices;
		std::string category; 

};




