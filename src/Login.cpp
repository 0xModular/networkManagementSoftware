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

	if(con == nullptr)
		return -1;

	sql::PreparedStatement* pstmt;
	pstmt = con->prepareStatement("SELECT type FROM users WHERE username = ? AND password = ?");
	pstmt->setString(1, this->username);
	pstmt->setString(2, this->password);

	sql::ResultSet* result = pstmt->executeQuery();

	if (result->next()) {
    
		std::string type;
		a = new Account(&(this->username), &type, new std::string("1"));
		delete con;
		delete result;
		delete pstmt;
		return 0; 

	} 
	else {

		pstmt = con->prepareStatement("SELECT username FROM users WHERE username = ?");
		pstmt->setString(1, this->username);

		if (result->next())
			return 1;
		else
			return 2;

	}

	

}
