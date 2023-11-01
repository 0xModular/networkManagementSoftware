#ifndef SRC_REFERENCEVALIDATIONMECHANISM_H_
#define SRC_REFERENCEVALIDATIONMECHANISM_H_

#include <string>

class Account;

class ReferenceValidationMechanism{

	public:

        ReferenceValidationMechanism(std::string type);
       // ReferenceValidationMechanism(std::string type, Account a);
        ~ReferenceValidationMechanism();
        static bool checkAuthorization(int level);

	private:

        void networkAdminTools();
        void accessLogin();
        void createAccount();
        void networkEngineerTools();
        

        std::string accessType;
        //Account *userAccount;


};


#endif /* SRC_LOGIN_H_ */
