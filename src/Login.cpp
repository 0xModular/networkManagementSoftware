/*
 * Login.cpp
 * Created on: Oct 24, 2023
 *
 * Author: Layne
 */

#include "Login.h"


//Constructor
Login::Login(std::string name, std::string passphrase){
            	
	this->username = name;
	this->password = passphrase;
	this->errorCode = -1;
            
}

Login::~Login(){



}


// Assuming you have a valid database connection (con).
int Login::SendInfoAndGetResponseStatus(Account *a){

	auto con = DatabaseConnection::GetSecureConnection("sample", "sample");

	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT username FROM users WHERE username = ? AND password = ?");
	pstmt->setString(1, this->username);
	pstmt->setString(2, this->password);

	sql::ResultSet* result = pstmt->executeQuery();

	if (result->next()) {
    
		// A matching record was found, so the login information is correct.

	} else {
    
		// No matching record found; the login information is incorrect.

	}


	delete con;
	delete result;
	delete pstmt;
	a = new Account(&(this->username), new std::string("admin"), new std::string("1"));
	return 1; //errorCode in future

}
