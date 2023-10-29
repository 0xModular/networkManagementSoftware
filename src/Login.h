#include <string>
#include "Account.h"

#ifndef SRC_LOGIN_H_
#define SRC_LOGIN_H_

class Login{

	public:
	
		Login(std::string type, std::string name, std::string password);
		~Login();

	private:

		Account createAccount();
		void encryptLoginInfo();
		void sendLoginInfo();
		Account waitforResponse(); //handles wrong password and account doesn't exist errors

		std::string username;
		std::string password;
		int loginAttempts;
		std::string type;



};


#endif /* SRC_LOGIN_H_ */
