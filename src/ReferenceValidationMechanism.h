#ifndef SRC_REFERENCEVALIDATIONMECHANISM_H_
#define SRC_REFERENCEVALIDATIONMECHANISM_H_

#include <string>
#include "Account.h"
#include "Network.h"
#include "Login.h"
#include "Device.h"

class Account;

class ReferenceValidationMechanism{

	public:

	        static void start(std::string type);
                ReferenceValidationMechanism(std::string type);
                ReferenceValidationMechanism(std::string type, Account *a);
                ~ReferenceValidationMechanism();
                bool checkAuthorization(int level);

                void networkAdminTools();
                Account* accessLogin(std::string name, std::string password, int *error);
                void createAccount();
                void networkEngineerTools();

	private:

        Network n;
        std::string accessType;
        Account *userAccount;


};


#endif /* SRC_LOGIN_H_ */