/*
 * ReferenceValidationMechanism.h
 * Created on: Oct 24, 2023
 *
 * Author:
 */

#pragma once
#include <iostream>
#include <string>
#include "Account.h"
#include "Network.h"
#include "Login.h"
#include "Device.h"

class Account;
class Network;
class Login;
class Device;

class ReferenceValidationMechanism{

	public:

                //useable
                ReferenceValidationMechanism();
                static std::string encryptString(std:: string s, int key);
                static std::string decryptString(std:: string s, int key);
                bool CheckAuthorization(int level);
                Network getNetwork();
                int AccountCreation(std::string name, std::string password, std::string type, std::string cat, Account *a);

                
                int AccessLogin(std::string name, std::string password); 


                //ignore for now
                ReferenceValidationMechanism(std::string type); //Constructors
                ReferenceValidationMechanism(std::string type, Account *a);
                void NetworkAdminTools(std::string option);
                void CreateAccount();
                void NetworkEngineerTools(std::string option);
                ~ReferenceValidationMechanism(); //Destructor
                Account getAccount();

	private:

		Network *n; //network to be worked with. Generated after login is completed
		Account *activeAccount; //logged in account. is a nullptr before login is completed

};


