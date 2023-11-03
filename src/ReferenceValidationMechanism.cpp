#ifndef SRC_REFERENCEVALIDATIONMECHANISM_I_
#define SRC_REFERENCEVALIDATIONMECHANISM_I_

#include "ReferenceValidationMechanism.h"
#include <iostream>


void ReferenceValidationMechanism::start(std::string type){


	ReferenceValidationMechanism *r = new ReferenceValidationMechanism("login");
	if(type.compare("login") == 0){
		    r = r->accessLogin();
	}
	else if(type.compare("createAccount") == 0){
		r = r->accessLogin();
	}

	if(r->accessType.compare("admin") == 0){
	    r->networkAdminTools();
	}
	else if(r->accessType.compare("engineer") == 0){
		r->networkEngineerTools();
	}

}

ReferenceValidationMechanism::ReferenceValidationMechanism(std::string type){

	userAccount = NULL;
    accessType = type;
}



ReferenceValidationMechanism::ReferenceValidationMechanism(std::string type, Account *a){

	userAccount = a;
	accessType = type;

}

ReferenceValidationMechanism* ReferenceValidationMechanism::accessLogin(){

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


    Account *a = l->waitForResponse(&type, &accountCategory);
    l->~Login();
    delete l;


    ReferenceValidationMechanism *r = new ReferenceValidationMechanism(type, a);

    return r;


}

void ReferenceValidationMechanism::networkAdminTools(){
    
    Network *n = new Network();

    std::string input;

    while (true){

    	std::cin >> input;

    	if (input.compare("dlist") == 0){
    		n->refresh(this);
    		std::vector<Device> d = n->getDeviceList(this);
    		int i;
    		for (i = 0; i < d.size(); i++){
    		std::cout << "IP: " << d.at(i).getIpv4(this) << " MAC: " << d.at(i).getMac(this) << " Static: " << d.at(i).getWired(this) << "\n";
    		}
    	}
    	else if (input.compare("add") == 0){


    	}
    }
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