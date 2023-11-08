#ifndef SRC_LOGIN_H_
#define SRC_LOGIN_H_

#include <string>
#include "Account.h"
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
class Account;

class Login{

	public:
	
		Login(std::string name, std::string password);
		~Login();
		Account createAccount();
		Account *generateEncryptedLoginConnection();

	private:

		Account *sendInfoAndGetResponse(std::string name, std::string pass, sql::Connection *con);

		std::string username;
		std::string password;
		int loginAttempts;



};


#endif /* SRC_LOGIN_H_ */