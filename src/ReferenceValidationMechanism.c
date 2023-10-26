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

ReferenceValidationMechanism::networkAdminTools(){
    


}

ReferenceValidationMechanism::networkEngineerTools(){



}

#endif