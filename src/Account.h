/*
 * Account.h
 * Created on: Oct 24, 2023
 *
 * Author: Layne
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

		//create account
		static int CreateNewAccountInDB(std::string name, std::string password1, std::string password2);


		//constructor/deconstructor
		Account(std::string name, std::string t, std::string cat); //Constructor
		~Account(); //Destructor
		

		//admin account edit tools
		static std::vector<Account> GetManagableAccounts(ReferenceValidationMechanism *r); //Gets accounts that an admin account can manage. Empty vecor in unsuccessful
		bool RemoveAccount(ReferenceValidationMechanism *r); //remove an account from the DB entirly
		bool LinkDevice(Device d, ReferenceValidationMechanism *r); //link device d to this account. Returns success or not. Sends notification to account
		bool UnlinkDevice(Device d, ReferenceValidationMechanism *r); //unlink device d from this account. Returns success or not. Sends notification to account
		bool SetAccountType(std::string type, ReferenceValidationMechanism *r); //used to set accounts with type "none" to their roles. Returns success or not.
		bool EditAccountName(std::string newName, ReferenceValidationMechanism *r); //change the username of an account. Returns success or not.
		bool ResetLoginAttempts(ReferenceValidationMechanism *r);
		std::vector<std::string> RetrieveAccountMessages(ReferenceValidationMechanism *r);
		bool RetrieveLinkedDevices(ReferenceValidationMechanism *r);
		bool ResetPassword(std::string newPass1, std::string newPass2, ReferenceValidationMechanism *r); 


		//getters
		std::string GetAccountType();
		std::string GetAccountName();
		std::string GetAccountCat();
		std::vector<Device> GetLinkedDeviceVec();

		//other
		static void SendMessageToAdmins(std::string m);



	private:

		//finished and ready
		bool NotifyAccount(std::string message, Account a, ReferenceValidationMechanism *r);

		//variables
		std::string type; 
		std::string userName;
		std::vector<Device> linkedDevices;
		std::string category; 

};




