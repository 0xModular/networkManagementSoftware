#ifndef SRC_LOGIN_H_
#define SRC_LOGIN_H_

#include <string>
#include "Account.h"
class Account;

class Login{

	public:
	
		Login(std::string name, std::string password);
		~Login();
		Account createAccount();
		Account *generateEncryptedLoginConnection();
		Account *sendInfoAndGetResponse(std::string name, std::string pass sql::Connection *con); //handles wrong password and account doesn't exist errors

	private:



		std::string username;
		std::string password;
		int loginAttempts;



};


#endif /* SRC_LOGIN_H_ */