/*
 * Login.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Light
 */

#ifndef FILES_LOGIN_H_
#define FILES_LOGIN_H_

#include <string>
#include "Account.h"

class Login{

	public:
		static Account displayLogin();

	private:

		Login::Login();
		Login::~Login();

		void encryptLoginInfo();
		void sendLoginInfo();
		void waitforResponse(); //handles wrong password and account doesn't exist errors

		string username;
		string password;
		int loginAttempts;



};


#endif /* FILES_LOGIN_H_ */
