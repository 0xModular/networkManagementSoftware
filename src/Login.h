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
#include <cppconn/connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "DatabaseConnection.h"

class Account;
class DatabaseConnection;

class Login{

	public:
	
		Login(std::string name, std::string password); //Constructor
		~Login(); //Destructor
		Account CreateAccount();
		int SendInfoAndGetResponseStatus(Account *a);

	private:

		

		std::string username;
		std::string password;
		int errorCode;

};


