/*
 * Login.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Light
 */
#include <string>
#include "Account.h"

#ifndef SRC_USERINTERFACE_H_
#define SRC_USERINTERFACE_H_

class UserInterface{

	public:

        UserInterface();
        ~UserInterface();

	private:

		std::string interfaceType;
        Account userAccount;


};


#endif /* SRC_LOGIN_H_ */
