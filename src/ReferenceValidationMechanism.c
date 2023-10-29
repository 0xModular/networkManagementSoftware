#ifndef SRC_USERINTERFACE_I_
#define SRC_USERINTERFACE_I_

#include "src/ReferenceValidationMechanism.h"
#include <string>


ReferenceValidationMechanism::ReferenceValidationMechanism(std::string type){

    this.account = null;
    this.type = interfaceType;

    if(){

    }

}

ReferenceValidationMechanism::ReferenceValidationMechanism(std::string type, Account a){

    this.account = userAccount;
    this.type = interfaceType;

    if(strcmp(type, "admin") == 0){
        this.networkAdminTools();
    }

}

void accessLogin(){

    Login l = new Login();
    std::string accountType;
    std::string accountCategory;

    l.encryptLoginInfo();
    l.sendLoginInfo();

    Account a = l.waitforResponse(accountType, accountCategory);
    this.userAccount = a;
    this.type = accountType;

    if(strcmp(this.type) == "Engineer"){

        this.networkEngineerTools();

    }
    else if(strcmp(this.type) == "Admin"){

        this.networkAdminTools();
        
    }
    else
        exit();


}

ReferenceValidationMechanism::networkAdminTools(){
    
    Network n = new Network();

}

ReferenceValidationMechanism::networkEngineerTools(){



}

#endif