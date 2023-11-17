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
	if(con == nullptr){

		con->close();
		return -1;

	}

	if (password1.compare(password2) != 0){

		con->close();
		return 2;

	}

	if (name.compare(NULL) || password1.compare(NULL) || password2.compare(NULL)){

		con->close();
		return 3;

	}
	
	sql::PreparedStatement* pstmt;

	pstmt = con->prepareStatement("SELECT username FROM users WHERE username = ?");
	pstmt->setString(1, name);

	sql::ResultSet* result = pstmt->executeQuery();

	if (result->next()) {
		con->close();
		return 1;
	}


    //std::string query = "INSERT INTO Accounts (UserName, Type, Password, LoginAttempts) VALUES ('" + name + "', '" + type + "', " + std::to_string(0) + ", '" + cat +"')";

    std::string query = "INSERT INTO Accounts (UserName, Type, Cat, Password, LoginAttempts) VALUES (?, ?, ?, ?, ?)";

    pstmt = con->prepareStatement(query);

    pstmt->setString(1, name);
    pstmt->setString(2, type);
    pstmt->setString(3, cat);
    pstmt->setString(4, password1);
    pstmt->setInt(5, 0);
    
    if (pstmt->executeUpdate() != 1) {
		
	    con->close();	
	    return -1;
	
    } else {
	
		a = new Account(&name, &type, &cat);
		con->close();
		return 0;	
	
    }

	return -1;

}
