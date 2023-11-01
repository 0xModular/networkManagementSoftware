#include <string>
#include "src/Account.h"

#ifndef SRC_USERINTERFACE_H_
#define SRC_USERINTERFACE_H_

class ReferenceValidationMechanism{

	public:

        ReferenceValidationMechanism(std::string type);
        ReferenceValidationMechanism(std::string type, Account a);
        ~ReferenceValidationMechanism();
        bool checkAuthorization(int level);

	private:

        void networkAdminTools();
        void accessLogin();
        void createAccount();
        void networkEngineerTools();
        

	std::string accessType;
        Account userAccount;


};


#endif 