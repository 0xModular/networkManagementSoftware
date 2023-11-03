#ifndef SRC_ACCOUNT_I_
#define SRC_ACCOUNT_I_

#include "Account.h"






std::vector<Account> Account::getManagableAccounts(ReferenceValidationMechanism *r){


}

void Account::removeAccount(ReferenceValidationMechanism *r){

} //Sends a request to the database to remove an account. First it checks if that account exists in the database using checkIfAccountExists.
Account Account::editAccount(ReferenceValidationMechanism *r){


}
Account Account::linkDevice(Device d, ReferenceValidationMechanism *r){


}
Account Account::unlinkDevice(Device d, ReferenceValidationMechanism *r){


}
void Account::getAccountDetails(std::string *name, std::string *type, std::string *category, std::vector<Device> *linkedDevices){}


void Account::EncryptOutgoingInfo(std::string *d){

}
bool Account::checkIfAccountExists(){

	return false;
}

Account::Account(std::string *name, std::string *t, std::string *cat){

	type = *t;
	userName = *name;
	category = *cat;

}
Account::Account(){}
Account::~Account(){}

#endif