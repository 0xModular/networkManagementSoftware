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
class Log;

class Account{

	public:


		//finished and ready

		//create account
		static int CreateNewAccountInDB(std::string name, std::string password1, std::string password2); //create new account in DB

		//constructor/deconstructor
		Account(std::string name, std::string t, std::string cat); //Constructor
		~Account(); //Destructor
		

		//admin get the accounts they can manage
		static std::vector<Account> GetManagableAccounts(ReferenceValidationMechanism *r); //Gets accounts that an admin account can manage. Empty vecor in unsuccessful

		//admin account edit tools. Returns if it succeded or not
		bool EditAccountName(std::string newName, ReferenceValidationMechanism *r); //change the username of an account. Returns success or not.
		bool LinkDevice(Device d, ReferenceValidationMechanism *r); //link device d to this account. Returns success or not. Sends notification to account
		bool RemoveAccount(ReferenceValidationMechanism *r); //remove an account from the DB entirly
		bool ResetLoginAttempts(ReferenceValidationMechanism *r); //Resets a managable account's login attempts
		bool ResetPassword(std::string newPass1, std::string newPass2, ReferenceValidationMechanism *r); //resets a managable account's password
		bool RetrieveLinkedDevices(ReferenceValidationMechanism *r); //retrieve the devices linked to an account
		bool SetAccountType(std::string type, ReferenceValidationMechanism *r); //used to set accounts with type "none" to their roles. Returns success or not.
		bool UnlinkDevice(Device d, ReferenceValidationMechanism *r); //unlink device d from this account. Returns success or not. Sends notification to account
		

		//getters
		std::string GetAccountCat();
		std::string GetAccountName();
		std::string GetAccountType();
		std::vector<Device> GetLinkedDeviceVec(); //!!MUST USE RetrieveLinkedDevices ON THIS ACCOUNT SUCCESFULLY FIRST!!
		
		
		//other
		static void NotifyAccount(std::string m, Account a); //send a message to a specific account
		std::vector<std::string> RetrieveAccountMessages(ReferenceValidationMechanism *r); //get all account messages from the database for an account
		static void SendMessageToAdmins(std::string m); //send message to all admins on a network



	private:

		//variables
		std::string type; 
		std::string userName;
		std::vector<Device> linkedDevices;
		std::string category; 

};




