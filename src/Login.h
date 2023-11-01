#ifndef SRC_LOGIN_H_
#define SRC_LOGIN_H_

#include <string>

class Account;

class Login{

	public:
	
		Login(std::string type, std::string name, std::string password);
		~Login();
		Account createAccount();
		void encryptLoginInfo();
		void sendLoginInfo();
		Account waitforResponse(std::string *type, std::string *category); //handles wrong password and account doesn't exist errors

	private:



		std::string username;
		std::string password;
		int loginAttempts;
		std::string type;



};


#endif /* SRC_LOGIN_H_ */
