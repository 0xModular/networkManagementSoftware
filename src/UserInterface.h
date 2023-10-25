/*
 * Login.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Light
 */
#include <string>
#include "src/Account.h"

#ifndef SRC_USERINTERFACE_H_
#define SRC_USERINTERFACE_H_

class UserInterface{

	public:

        UserInterface(std::string type);
        UserInterface(std::string type, Account a);
        ~UserInterface();

	private:

        networkAdminTools();
        networkEngineerTools();
        checkAuthorization();
		std::string interfaceType;
        Account userAccount;


};


#endif /* SRC_LOGIN_H_ */
