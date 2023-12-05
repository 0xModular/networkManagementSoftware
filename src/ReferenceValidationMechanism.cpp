/*
 * ReferenceValidationMechanism.cpp
 * Created on: Oct 24, 2023
 *
 * Author:
 */

#include "ReferenceValidationMechanism.h"




//Working \/\/\/

//create account
int ReferenceValidationMechanism::AccountCreation(std::string name, std::string password1, std::string password2){

    return Account::CreateNewAccountInDB(name, password1, password2);

}

//automatically updates the rvm active account if login succedes
int ReferenceValidationMechanism::AccessLogin(std::string name, std::string password){
    
    Login *l = new Login(name, password);
    std::string accountType;
    std::string accountCategory;
	Account *user;
	int errorCode = l->SendInfoAndGetResponseStatus(user);

	if (errorCode == 0){

		//log successful login
		std::stringstream logMessage;
		logMessage << "Login on account " << name << " success";
		if(!Log::CreateNewEventLogInDB(logMessage.str(), *user))
			return -1; //if log fails then login fails

		this->activeAccount = new Account(user->GetAccountName(), user->GetAccountType(), user->GetAccountCat());
		if(this->activeAccount->GetAccountType().compare("admin") == 0 || this->activeAccount->GetAccountType().compare("engineer") == 0) 
			this->n = new Network(this);
		
		return errorCode;

	} 
	else{

		std::stringstream logMessage;
		logMessage << "Attempted login on account " << name << " failed";
		Log::CreateNewEventLogInDB(logMessage.str(), Account(name, "unknown", "unknown"));
	
	}

	return errorCode;
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

Account ReferenceValidationMechanism::GetAccount(){

	return *this->activeAccount;

}


std::string ReferenceValidationMechanism::EncryptString(std::string s, int key) {
    int length = s.length();

    for (int i = 0; i < key; ++i) {
        char lastChar = s.back();  // Get the last character
        s.pop_back();  // Remove the last character
        s = lastChar + s;  // Add the last character to the beginning
    }

    return s;
}


std::string ReferenceValidationMechanism::DecryptString(std::string s, int key) {

    for (int i = 0; i < key; ++i) {
        char firstChar = s[0];  // Get the first character
        s.erase(0, 1);  // Remove the first character
        s += firstChar;  // Add the first character to the end
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
        
		std::cerr << "Authorization Error, Exiting...";
        exit(1);
    }
    
	return false;

}




//wip \/\/\/


ReferenceValidationMechanism::ReferenceValidationMechanism(bool b){ //will be removed

	std::string s = Network::GatewayMac();
	this->activeAccount = new Account("t1", "admin", s);


}