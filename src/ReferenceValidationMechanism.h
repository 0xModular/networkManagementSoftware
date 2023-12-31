/*
 * ReferenceValidationMechanism.h
 * Created on: Oct 24, 2023
 *
 * Author: Layne
 */

#pragma once
#include <iostream>
#include <string>
#include "Account.h"
#include "Network.h"
#include "Login.h"
#include "Device.h"

class Network;
class Login;
class Account; 

class ReferenceValidationMechanism{

	public:

        //useable
        ReferenceValidationMechanism();
        static std::string EncryptString(std:: string s, int key);
        static std::string DecryptString(std:: string s, int key);
        bool CheckAuthorization(int level);
        Network* GetNetwork();
        int AccountCreation(std::string name, std::string password1, std::string password2);
        Account GetAccount();
        int AccessLogin(std::string name, std::string password); 


        //ignore for now
        ReferenceValidationMechanism(bool b); //Constructors
        ReferenceValidationMechanism(std::string type, Account *a);
        void NetworkAdminTools(std::string option);
        void CreateAccount();
        void NetworkEngineerTools(std::string option);
        ~ReferenceValidationMechanism(); //Destructor

	private:

		Network *n; //network to be worked with. Generated after login is completed
		Account *activeAccount; //logged in account. is a nullptr before login is completed

};


