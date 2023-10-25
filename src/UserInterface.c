#ifndef SRC_USERINTERFACE_I_
#define SRC_USERINTERFACE_I_

#include "src/UserInterface.h"
#include <string>

Device::Device(std::string type){

    this.account = null;
    this.type = interfaceType;

    if(){

    }

}

Device::Device(std::string type, Account a){

    this.account = userAccount;
    this.type = interfaceType;

    if(strcmp(type, "admin") == 0){
        this.networkAdminTools();
    }

}

UserInterface::networkAdminTools(){
    


}

UserInterface::networkEngineerTools(){



}

#endif