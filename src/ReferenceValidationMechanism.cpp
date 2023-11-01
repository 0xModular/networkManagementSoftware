#ifndef SRC_REFERENCEVALIDATIONMECHANISM_I_
#define SRC_REFERENCEVALIDATIONMECHANISM_I_

#include "ReferenceValidationMechanism.h"

#include <iostream>

#include "Login.h"

class Network;


ReferenceValidationMechanism::ReferenceValidationMechanism(std::string type){

	//userAccount = NULL;
    accessType = type;

    //if(){

    //}

}

/*ReferenceValidationMechanism::ReferenceValidationMechanism(std::string type, Account a){

	userAccount = a;
	accessType = type;

    if(accessType.compare("admin") == 0){
        networkAdminTools();
    }
    else if(accessType.compare("engineer") == 0){
    	networkEngineerTools();
    }

}*/

void accessLogin(){

    std::string type;
    std::string name;
    std::string password;
    std::cin >> type;
    std::cin >> name;
    std::cin >> password;

    Login *l = new Login(type, name, password);
    std::string accountType;
    std::string accountCategory;

    l->encryptLoginInfo();
    l->sendLoginInfo();

    //Account *a = l->waitforResponse(&type, &accountCategory);
    //l.~Login();

    //ReferenceValidationMechanism r(type, a);


}

void ReferenceValidationMechanism::networkAdminTools(){
    
    Network n();

}

void ReferenceValidationMechanism::networkEngineerTools(){



}

ReferenceValidationMechanism::~ReferenceValidationMechanism(){




}


bool ReferenceValidationMechanism::checkAuthorization(int level){

    if (level == 1 && (accessType.compare("engineer") == 0 || accessType.compare("admin") == 0)){
        return true;
    }
    else if (level == 2 && accessType.compare("admin")){
        return true;
    }
    else {
        //error
        return false;
    }
    return false;

}

#endif
