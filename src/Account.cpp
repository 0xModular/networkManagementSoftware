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

std::string Account::GetAccountName(){

	return this->userName;

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

int Account::CreateNewAccountInDB(std::string name, std::string password1, std::string password2, std::string type, std::string cat, Account *a){

	sql::Connection* con = DatabaseConnection::GetSecureConnection("account", "account");
	if(con == nullptr)
		return -1;

	if (password1.compare(password2) != 0)
		return 2;

	if (name.compare(NULL) || password1.compare(NULL) || password2.compare(NULL))
		return 3;

	
	sql::PreparedStatement* pstmt;

	pstmt = con->prepareStatement("SELECT username FROM users WHERE username = ?");
	pstmt->setString(1, name);

	sql::ResultSet* result = pstmt->executeQuery();

	if (result->next()) 
		return 1;


    std::string query = "INSERT INTO Accounts (UserName, Type, Password, LoginAttempts) VALUES ('" + name + "', '" + type + "', " + std::to_string(0) + ", '" + cat +"')";

    if (sql::mysql_query(con, query.c_str())) 
		return -1;
    else{
		a = new Account(&name, &type, &cat);
		return 0;
	}



}