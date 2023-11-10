/*
 * ReferenceValidationMechanism.cpp
 * Created on: Oct 24, 2023
 *
 * Author:
 */

#include "ReferenceValidationMechanism.h"

//"login"4
ReferenceValidationMechanism::ReferenceValidationMechanism(std::string type){

	if(type.compare("login") == 0) {
		this->accessType = type;
	} else if(type.compare("createAccount") == 0) {

		this->accessType = type;
	
	}

}

ReferenceValidationMechanism::ReferenceValidationMechanism(std::string type, Account *a){
 
	if(type.compare("admin") == 0) {
		
		this->accessType = type;
        	auto n = new Network();
        	this->userAccount = a;
	
	} else if(type.compare("engineer") == 0) {
		
		this->accessType = type;
        	auto n = new Network();
        	this->userAccount = a;
	
	}

}

static std::string encryptString(std:: string s, int key){

	char temp;
	int i;
	for(i = 0; i < key; i++){
		temp = s.at(s.size() - 1);
		s.pop_back();
		s = temp + s;
	}

	return s;

}


static std::string decryptString(std:: string s, int key){

	char temp;
	int i;
	for(i = 0; i < key; i++){
		temp = s.at(0);
		s.pop_back();
		s = s + temp;
	}

	return s;

}


Account* ReferenceValidationMechanism::AccessLogin(std::string name, std::string password, int *error){
    
	std::string loginScreenReturnValue;
    
    	Login *l = new Login(name, password);
    	std::string accountType;
    	std::string accountCategory;
    	Account *a = l->GenerateEncryptedLoginConnection();
    
	if (a == NULL) {
        
		*error = 1;
		return NULL;
    
	} else {
        
		*error = 0;
        	return a;
    
	}

}

void ReferenceValidationMechanism::NetworkAdminTools(std::string option){
    
	if(this->userAccount->GetAccountType().compare("admin") != 0) {
        
		exit(1);
    
	}

	if (option.compare("dlist") == 0) {
    	
		this->n->Refresh(this);
    		std::vector<Device> d = n->GetDeviceList(this);
    		int i;
    	
		for (i = 0; i < d.size(); i++) {
    	
			std::cout << "Name: " << d.at(i).GetName(this) << " IP: " << d.at(i).GetIpv4(this) << " MAC: " << d.at(i).GetMac(this) << " Wired(1 is true): " << d.at(i).GetWired(this) << "\n";
    	
		}
    
	}
    
	else if (option.compare("add") == 0) {
    	
    

	}

}

void ReferenceValidationMechanism::NetworkEngineerTools(std::string option){

	if(this->userAccount->GetAccountType().compare("engineer") != 0){
        
		exit(1);
    
	}
    
	if (option.compare("dlist") == 0) {
    	
		this->n->Refresh(this);
		std::vector<Device> d = n->GetDeviceList(this);
    		int i;
    	
		for (i = 0; i < d.size(); i++) {
    	
			std::cout << "Name: " << d.at(i).GetName(this) << " IP: " << d.at(i).GetIpv4(this) << " MAC: " << d.at(i).GetMac(this) << " Wired(1 is true): " << d.at(i).GetWired(this) << "\n";
    	
		}
    
	} else if (option.compare("add") == 0) {


    	
	}

}

ReferenceValidationMechanism::~ReferenceValidationMechanism(){



}


bool ReferenceValidationMechanism::CheckAuthorization(int level){

    
	if (level == 1 && (this->accessType.compare("engineer") == 0 || accessType.compare("admin") == 0)){
        
		return true;
    
	} else if (level == 2 && this->accessType.compare("admin")){
        
		return true;
    
	}
    
	else {
        
		//error
        	exit(1);
    	}
    
	return false;

}

