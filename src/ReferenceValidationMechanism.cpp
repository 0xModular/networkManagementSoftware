#ifndef SRC_REFERENCEVALIDATIONMECHANISM_I_
#define SRC_REFERENCEVALIDATIONMECHANISM_I_

#include "ReferenceValidationMechanism.h"
#include <iostream>

//"login"4
ReferenceValidationMechanism::ReferenceValidationMechanism(std::string type){


	if(type.compare("login") == 0){
		accessType = type;
	}
	else if(type.compare("createAccount") == 0){
		accessType = type;
	}

	

}

ReferenceValidationMechanism::ReferenceValidationMechanism(std::string type, Account *a){

    
    if(type.compare("admin") == 0){
	    accessType = type;
        n = Network();
        userAccount = a;
	}
	else if(type.compare("engineer") == 0){
		accessType = type;
        n = Network();
        userAccount = a;
	}

}



ReferenceValidationMechanism::ReferenceValidationMechanism(std::string type, Account *a){

	userAccount = a;
	accessType = type;

}

Account* ReferenceValidationMechanism::accessLogin(std::string name, std::string password, int *error){

    std::string loginScreenReturnValue;
    
    Login *l = new Login(name, password);
    std::string accountType;
    std::string accountCategory;
    Account *a = l->generateEncryptedLoginConnection();
    if (a == NULL){
        *error = 1;
        return NULL;
    }
    else{
        *error = 0;
        return a;
    }



}

void ReferenceValidationMechanism::networkAdminTools(){
    
    Network *n = new Network();

    std::string input;

    while (true){

        std::cout << "type \"dlist\"\n";
    	std::cin >> input;

    	if (input.compare("dlist") == 0){

    		n->refresh(this);
    		std::vector<Device> d = n->getDeviceList(this);
    		int i;
    		for (i = 0; i < d.size(); i++){
    		std::cout << "Name: " << d.at(i).getName(this) << " IP: " << d.at(i).getIpv4(this) << " MAC: " << d.at(i).getMac(this) << " Wired(1 is true): " << d.at(i).getWired(this) << "\n";
    		}
    	}
    	else if (input.compare("add") == 0){


    	}
    }
}

void ReferenceValidationMechanism::networkEngineerTools(){

 Network *n = new Network();

    std::string input;

    while (true){

        std::cout << "type \"dlist\"\n";
    	std::cin >> input;

    	if (input.compare("dlist") == 0){

    		n->refresh(this);
    		std::vector<Device> d = n->getDeviceList(this);
    		int i;
    		for (i = 0; i < d.size(); i++){
    		std::cout << "Name: " << d.at(i).getName(this) << " IP: " << d.at(i).getIpv4(this) << " MAC: " << d.at(i).getMac(this) << " Wired(1 is true): " << d.at(i).getWired(this) << "\n";
    		}
    	}
    	else if (input.compare("add") == 0){


    	}
    }


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
        exit(1);
    }
    return false;

}

#endif