/*
 * Login.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Light
 */
#include <string>
#include "Account.h"

#ifndef SRC_LOGIN_H_
#define SRC_LOGIN_H_

class Login{

	public:
	
		static Account displayLogin();

	private:

		Login::Login();
		Login::~Login();

		void encryptLoginInfo();
		void sendLoginInfo();
		void waitforResponse(); //handles wrong password and account doesn't exist errors

		std::string username;
		std::string password;
		int loginAttempts;
		std::string type;



};


#endif /* SRC_LOGIN_H_ */
