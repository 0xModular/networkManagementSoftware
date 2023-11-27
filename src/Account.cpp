/*
 * Account.cpp
 * Created on: Oct 24, 2023
 *
 * Author:
 */


#include "Account.h"

std::vector<Account> Account::GetManagableAccounts(ReferenceValidationMechanism *r){
    
    auto con = DatabaseConnection::GetSecureConnection("netadmin", "netadmin");

    std::vector<Account> accountVec;

    if (con == nullptr || !r->CheckAuthorization(2)){
		delete con;
        std::stringstream logMessage;
        logMessage << "Accounts for network category " << r->GetAccount().GetAccountCat() << " retrieve attempt failed";
        Log::CreateNewEventLogInDB(logMessage, r);
        return accountVec;
	}

    try {

            std::string query = "SELECT UserName, Type, Category FROM Accounts WHERE Category = ? AND Type != ?";
            std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(query));
            pstmt->setString(1, r->GetAccount().GetAccountCat());
            pstmt->setString(2, "admin");

            std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
            while (res->next()) {
                
                std::string name = res->getString("col1");
                std::string accType = res->getString("col2");
                std::string cat = res->getString("col3");
                Account a(name, accType, cat);
                accountVec.push_back(a);
            }
        }
    
    catch (sql::SQLException& e) {
        std::stringstream logMessage;
        logMessage << "Accounts for network category " << r->GetAccount().GetAccountCat() << " retrieve attempt failed";
        Log::CreateNewEventLogInDB(logMessage, r);
		accountVec.clear();
        return accountVec; 
    }

    std::stringstream logMessage;
    logMessage << "Accounts for network category " << r->GetAccount().GetAccountCat() << " retrieved successfully";
	if(!Log::CreateNewEventLogInDB(logMessage, r))
		accountVec.clear(); //if log fails then this function fails
     

    return accountVec;

}

bool Account::RemoveAccount(ReferenceValidationMechanism *r){

    auto con = DatabaseConnection::GetSecureConnection("netadmin", "netadmin");

    if (con == nullptr || !r->CheckAuthorization(2)){
		delete con;
        std::stringstream logMessage;
        logMessage << "Attempt to delete account " << this->userName << " failed";
	    Log::CreateNewEventLogInDB(logMessage, r);
	    return false; 
	}

    try{

        std::string query = "DELETE FROM Accounts WHERE type != ? AND UserName = ? AND Category = ?";
        std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(query));
        pstmt->setString(1, "admin");
        pstmt->setString(2, this->userName);
        pstmt->setString(3, r->GetAccount().userName);
        pstmt->execute();

    } 
    catch (sql::SQLException& e) {

        std::stringstream logMessage;
        logMessage << "Attempt to delete account " << this->userName << " failed";
	    Log::CreateNewEventLogInDB(logMessage, r);
	    return false; 
    
    }

    std::stringstream logMessage;
    logMessage << "Account " << this->userName << " succesfully deleted";
	if(!Log::CreateNewEventLogInDB(logMessage, r))
		return false; //if log fails then this function fails

} 

bool Account::EditAccountName(std::string newName, ReferenceValidationMechanism *r){
  
    auto con = DatabaseConnection::GetSecureConnection("login", "login");

    if (con == nullptr || !r->CheckAuthorization(2)){
		delete con;
        std::stringstream logMessage;
        logMessage << "Attempt to update account name for account " << this->userName << " to " << newName << " failed";
	    Log::CreateNewEventLogInDB(logMessage, r);
	    return false; 
	}

    try{

        std::string query = "UPDATE Accounts SET UserName = ? WHERE UserName = ?";
        std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(query));
        pstmt->setString(1, newName);
        pstmt->setString(2, this->userName);
        pstmt->execute();

    } 
    catch (sql::SQLException& e) {

        std::stringstream logMessage;
        logMessage << "Attempt to update account name for account " << this->userName << " to " << newName << " failed";
	    Log::CreateNewEventLogInDB(logMessage, r);
	    return false; 
    
    }

    std::stringstream logMessage;
    logMessage << "Attempt to update account name for account " << this->userName << " to " << newName << " failed";
	if(!Log::CreateNewEventLogInDB(logMessage, r))
		return false; //if log fails then this function fails

}

Account Account::LinkDevice(Device d, ReferenceValidationMechanism *r){


}

Account Account::UnlinkDevice(Device d, ReferenceValidationMechanism *r){


}

Account::Account(std::string name, std::string t, std::string cat){

	this->type = t;
	this->userName = name;
	this->category = cat;

}

Account::~Account(){


}

int Account::CreateNewAccountInDB(std::string name, std::string password1, std::string password2, std::string type, std::string cat, Account *&a) {

    sql::Connection* con = DatabaseConnection::GetSecureConnection("account", "account");

    if (con == nullptr) {
        delete con;
        return -1;
    }

    if (password1 != password2) {
        delete con;
        return 2;
    }

    if (name.empty() || password1.empty() || password2.empty()) {
        delete con;
        return 3;
    }

    sql::PreparedStatement *pstmt;
    sql::ResultSet *result;

    pstmt = con->prepareStatement("SELECT username FROM users WHERE username = ?");
    pstmt->setString(1, name);

    result = pstmt->executeQuery();

    if (result->next()) {
        delete con;
        return 1;
    }

    delete pstmt;
    delete result;

    pstmt = con->prepareStatement("INSERT INTO Accounts (UserName, Type, Password, LoginAttempts) VALUES (?, ?, ?, ?)");
    pstmt->setString(1, name);
    pstmt->setString(2, type);
    pstmt->setString(3, ReferenceValidationMechanism::EncryptString(password1, 34)); // Ensure proper encryption or hashing for passwords
    pstmt->setInt(4, 0); // Assuming LoginAttempts default value is 0

    try {
        pstmt->executeUpdate();
        delete pstmt;

        // Create Account object
        a = new Account(name, type, "cat");
        if (!Log::CreateNewEventLogInDB("new account created success", *a))
            return -1;
        else{
            delete con;
            return 0;
        }
    } catch (sql::SQLException& e) {
        //Log::CreateNewEventLogInDB("new account created failed");
        delete con;
        return -1;
    }
}

bool Account::NotifyAccount(std::string message, Account a, ReferenceValidationMechanism *r){

    auto con = DatabaseConnection::GetSecureConnection("netadmin", "netadmin");

     if (con == nullptr) {
        delete con;
        return false;
    }

    try{

    sql::PreparedStatement *pstmt;
    sql::ResultSet *result;

    pstmt = con->prepareStatement("INSERT INTO Accounts (Account, message) VALUES (?, ?)");
    pstmt->setString(1, a.GetAccountName());
    pstmt->setString(2, message);

    } 
    catch (sql::SQLException& e) {

        std::stringstream logMessage;
        logMessage << "Attempt to delete account " << this->userName << " failed";
	    Log::CreateNewEventLogInDB(logMessage, r);
	    return false; 
    
    }

    std::stringstream logMessage;
    logMessage << "Account " << this->userName << " succesfully deleted";
	if(!Log::CreateNewEventLogInDB(logMessage, r))
		return false; //if log fails then this function fails

    return true;

}


std::string Account::GetAccountType(){

	return this->type;

}

std::string Account::GetAccountName(){

	return this->userName;

}

std::string Account::GetAccountCat(){

	return this->category;

}
