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


//login to database
int Login::SendInfoAndGetResponseStatus(Account *&a) {
    auto con = DatabaseConnection::GetSecureConnection("login", "login");

    if (con == nullptr){
		delete con;
        return -1;
	}

    try {
        sql::PreparedStatement *prep_stmt;
        prep_stmt = con->prepareStatement("SELECT LoginAttempts FROM Accounts WHERE UserName = ?");
        prep_stmt->setString(1, this->username);

        sql::ResultSet *res = prep_stmt->executeQuery();

        if (!res->next()) {
            delete res;
            delete prep_stmt;
            delete con;
            return 1;
        } else {
            int loginAttempts = res->getInt("LoginAttempts");
            delete res;
            delete prep_stmt;

            if (loginAttempts > 10) {
                delete con;
                return 3;
            }

            sql::Statement *stmtUpdate;
            stmtUpdate = con->createStatement();
            std::string updateQuery = "UPDATE Accounts SET LoginAttempts = LoginAttempts + 1 WHERE UserName = '" + this->username + "'";
            stmtUpdate->execute(updateQuery);
            delete stmtUpdate;

            sql::PreparedStatement *prep_stmt2;
            prep_stmt2 = con->prepareStatement("SELECT Type FROM Accounts WHERE UserName = ? AND Password = ?");
            prep_stmt2->setString(1, this->username);
            prep_stmt2->setString(2, ReferenceValidationMechanism::encryptString(this->password, 34));

            sql::ResultSet *res2 = prep_stmt2->executeQuery();

            if (!res2->next()) {
                delete res2;
                delete prep_stmt2;
                delete con;
                return 2;
            } else {
                std::string type = res2->getString("Type");
                a = new Account(this->username, type, "placeholder");
                delete res2;
                delete prep_stmt2;
                delete con;
                return 0;
            }
        }
    } 
	catch (sql::SQLException &e) {
        delete con; // Close the connection in case of an exception
        return -1;  // Return an error code
    }
}

        
    
 /*
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
*/
