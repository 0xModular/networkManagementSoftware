/*
 * Account.cpp
 * Created on: Oct 24, 2023
 *
 * Author:
 */


#include "Account.h"

std::string Account::GetAccountType(){

	return this->type;

}

std::vector<Account> Account::GetManagableAccounts(ReferenceValidationMechanism *r){


}

void Account::RemoveAccount(ReferenceValidationMechanism *r){

} //Sends a request to the database to remove an account. First it checks if that account exists in the database using checkIfAccountExists.

Account Account::EditAccount(ReferenceValidationMechanism *r){


}

Account Account::LinkDevice(Device d, ReferenceValidationMechanism *r){


}

Account Account::UnlinkDevice(Device d, ReferenceValidationMechanism *r){


}

void Account::GetAccountDetails(std::string *name, std::string *type, std::string *category, std::vector<Device> *linkedDevices){


}

void Account::EncryptOutgoingInfo(std::string *d){

}

bool Account::CheckIfAccountExists(){

	return false;
}

Account::Account(std::string *name, std::string *t, std::string *cat){

	this->type = *t;
	this->userName = *name;
	this->category = *cat;

}

Account::Account(){


}

Account::~Account(){


}
