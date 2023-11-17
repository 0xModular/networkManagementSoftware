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


Network* ReferenceValidationMechanism::GetNetwork(){

	if (activeAccount != nullptr && (activeAccount->GetAccountType().compare("admin") == 0 || activeAccount->GetAccountType().compare("engineer") == 0)){
		return n;
	}
	else if (activeAccount == nullptr){
		std::cout << "\nno account logged in, getNetwork() will return garbage code. In later versions this error will exit(1)\n";
	}
	else{
		std::cout << "\nactive account is not of admin or engineer type and is unauthorized, getNetwork() will return garbage code. In later versions this error will exit(1)\n";
	}

}


std::string ReferenceValidationMechanism::EncryptString(std:: string s, int key){

	char temp;
	int i;
	for(i = 0; i < key; i++){
		temp = s.at(s.size() - 1);
		s.pop_back();
		s = temp + s;
	}

	return s;

}


std::string ReferenceValidationMechanism::DecryptString(std:: string s, int key){

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

 	n = nullptr;
 	activeAccount = nullptr;

}


bool ReferenceValidationMechanism::CheckAuthorization(int level){

    
	if (level == 1 && (this->activeAccount->GetAccountType().compare("engineer") == 0 || this->activeAccount->GetAccountType().compare("admin") == 0)){
        
		return true;
    
	} else if (level == 2 && this->activeAccount->GetAccountType().compare("admin") == 0){
        
		return true;
    
	}
    
	else {
        
		//error
        	exit(1);
    	}
    
	return false;

}




//wip \/\/\/

int ReferenceValidationMechanism::AccountCreation(std::string name, std::string password1, std::string password2, std::string type, std::string cat){

	Account *a;
    int errorCode = Account::CreateNewAccountInDB(name, password1, password2, type, cat, a);

	if (errorCode = 0){

		this->activeAccount = a;
		this->n = new Network();
		delete a;
		return errorCode;

	} 
	else{

		delete a;
		return errorCode;

	}


}
