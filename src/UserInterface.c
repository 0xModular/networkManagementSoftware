#ifndef SRC_USERINTERFACE_I_
#define SRC_USERINTERFACE_I_

#include "src/UserInterface.h"
#include <string>

Device::Device(std::string type){


}

Device::Device(std::string type, Account a){

    this.account = userAccount;
    this.type = interfaceType;

    if(strcmp(type, "admin") == 0){
        this.networkAdminTools();
    }

}

//remove
Device::~Device()
{
}

//view
getDeviceDetails()
{
}

//edit (calls validateDeviceDetailInputs)
setDeviceDetails()
{
}

#endif