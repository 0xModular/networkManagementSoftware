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

std::string Account::GetAccountCat(){

	return this->category;

}

std::vector<Account> Account::GetManagableAccounts(ReferenceValidationMechanism *r){


}

void Account::RemoveAccount(ReferenceValidationMechanism *r){

} 

Account Account::EditAccount(ReferenceValidationMechanism *r){


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

Account::Account(){


}

Account::~Account(){


}

int Account::CreateNewAccountInDB(std::string name, std::string password1, std::string password2, std::string type, std::string cat, Account *&a) {

    sql::Connection* con = DatabaseConnection::GetSecureConnection("account", "account");

    if (con == nullptr) {
        return -1;
    }

    if (password1 != password2) {
        sql::mysql_close(con);
        return 2;
    }

    if (name.empty() || password1.empty() || password2.empty()) {
        sql::mysql_close(con);
        return 3;
    }

    sql::PreparedStatement *pstmt;
    sql::ResultSet *result;

    pstmt = con->prepareStatement("SELECT username FROM users WHERE username = ?");
    pstmt->setString(1, name);

    result = pstmt->executeQuery();

    if (result->next()) {
        sql::mysql_close(con);
        return 1;
    }

    delete pstmt;
    delete result;

    pstmt = con->prepareStatement("INSERT INTO Accounts (UserName, Type, Password, LoginAttempts) VALUES (?, ?, ?, ?)");
    pstmt->setString(1, name);
    pstmt->setString(2, type);
    pstmt->setString(3, ReferenceValidationMechanism::encryptString(password1, 34)); // Ensure proper encryption or hashing for passwords
    pstmt->setInt(4, 0); // Assuming LoginAttempts default value is 0

    try {
        pstmt->executeUpdate();
        delete pstmt;

        // Create Account object (ensure proper constructor for Account class)
        a = new Account(name, type, "cat");
        sql::mysql_close(con);
        return 0;
    } catch (sql::SQLException& e) {
        // Handle any exceptions or errors that might occur during the query execution
        sql::mysql_close(con);
        return -1;
    }
}
