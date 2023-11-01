#ifndef SRC_USERINTERFACE_I_
#define SRC_USERINTERFACE_I_

#include "src/ReferenceValidationMechanism.h"
#include <string>
#include <iostream>


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

    std::string type;
    std::string name;
    std::string password;
    cin >> type;
    cin >> name;
    cin >> password;

    Login l = new Login(type, name, password);
    std::string accountType;
    std::string accountCategory;

    l.encryptLoginInfo();
    l.sendLoginInfo();

    Account a = l.waitforResponse(accountType, accountCategory);
    this.userAccount = a;
    this.type = accountType;
    l.~Login();

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

    Network n = new Network();

    

}

bool ReferenceValidationMechanism::checkAuthorization(int level){

    if (level == 1 && (accessType.compare("engineer") == 0 || accessType.compare("admin") == 0){
        return true;
    }
    else if (level == 2 && accessType.compare("admin")){
        return true;
    }
    else {
        //error
        return false;
    }

}

#endif