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

	        static void Start(std::string type);
                ReferenceValidationMechanism(std::string type); //Constructors
                ReferenceValidationMechanism(std::string type, Account *a);
                ~ReferenceValidationMechanism(); //Destructor
                bool CheckAuthorization(int level);

                void NetworkAdminTools(std::string option);
                Account* AccessLogin(std::string name, std::string password, int *error);
                void CreateAccount();
                void NetworkEngineerTools(std::string option);

	private:

		Network *n;
        	std::string accessType;
		Account *userAccount;

};


