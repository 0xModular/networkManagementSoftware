/*
 * ReferenceValidationMechanism.cpp
 * Created on: Oct 24, 2023
 *
 * Author:
 */

#include "ReferenceValidationMechanism.h"




//Working \/\/\/

//automatically updates the rvm active account if login succedes
int ReferenceValidationMechanism::AccessLogin(std::string name, std::string password){
    

    	Login *l = new Login(name, password);
    	std::string accountType;
    	std::string accountCategory;
	Account *user;
	int errorCode = l->SendInfoAndGetResponseStatus(user);



	if (errorCode = 0){

   		delete l;
		this->activeAccount = user;
		this->n = new Network();
		delete user;
	
		return errorCode;

	} else{

		delete l;
		delete user;
	
		return errorCode;

	}

}


Network ReferenceValidationMechanism::getNetwork(){

	if (activeAccount != nullptr && (activeAccount->GetAccountType().compare("admin") == 0 || activeAccount->GetAccountType().compare("engineer") == 0)){
		return *n;
	}
	else if (activeAccount == nullptr){
		std::cout << "no account logged in, getNetwork() will return garbage code. In later versions this error will exit(1)";
	}
	else{
		std::cout << "active account is not of admin or engineer type and is unauthorized, getNetwork() will return garbage code. In later versions this error will exit(1)";
	}

}


std::string ReferenceValidationMechanism::encryptString(std:: string s, int key){

	char temp;
	int i;
	for(i = 0; i < key; i++){
		temp = s.at(s.size() - 1);
		s.pop_back();
		s = temp + s;
	}

	return s;

}


std::string ReferenceValidationMechanism::decryptString(std:: string s, int key){

	char temp;
	int i;
	for(i = 0; i < key; i++){
		temp = s.at(0);
		s.pop_back();
		s = s + temp;
	}

	return s;

}

ReferenceValidationMechanism::ReferenceValidationMechanism(){



}



















//Layne, next time, please make sure you have compileable code before you commit. 


//wip \/\/\/

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

