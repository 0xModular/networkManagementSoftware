/*
 * Login.h
 * Created on: Oct 24, 2023
 *
 * Author: Layne
 */

#pragma once
#include <iostream>
#include <string>
#include "Account.h"
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>


class Account;

class Login{

	public:
	
		Login(std::string name, std::string password); //Constructor
		~Login(); //Destructor
		Account CreateAccount();
		Account *GenerateEncryptedLoginConnection();

	private:

		Account *SendInfoAndGetResponseStatus(std::string name, std::string pass, sql::Connection *con);

		std::string username;
		std::string password;
		int loginAttempts;

};


