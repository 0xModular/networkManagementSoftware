/*
 * Login.cpp
 * Created on: Oct 24, 2023
 *
 * Author: Layne
 */

#include "Login.h"
#include "Database.h"

//Constructor
Login::Login(std::string name, std::string passphrase){
            	
	this->username = name;
	this->password = passphrase;
	this->loginAttempts = 0;
            
}

Login::~Login(){



}

Account* Login::GenerateEncryptedLoginConnection(){



		return SendInfoAndGetResponseStatus(username, password, &getSecureConnection("sample", "sample"));

    	

}


// Assuming you have a valid database connection (con).
Account* Login::SendInfoAndGetResponseStatus(std::string name, std::string pass, sql::Connection *con){

	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT username FROM users WHERE username = ? AND password = ?");
	pstmt->setString(1, name);
	pstmt->setString(2, pass);

	sql::ResultSet* result = pstmt->executeQuery();

	if (result->next()) {
    
		// A matching record was found, so the login information is correct.

	} else {
    
		// No matching record found; the login information is incorrect.

	}


	delete *con;
	delete result;
	delete pstmt;
	Account *a = new Account(&name, new std::string("admin"), new std::string("1"));
	return a;

}
