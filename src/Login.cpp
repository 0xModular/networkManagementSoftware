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

    //check if connection is established
    if (con == nullptr){
		delete con;
        return -1;
	}
    
    try {

        
        sql::PreparedStatement *prep_stmt;
        prep_stmt = con->prepareStatement("SELECT LoginAttempts FROM Accounts WHERE UserName = ?");
        prep_stmt->setString(1, this->username);

        sql::ResultSet *res = prep_stmt->executeQuery();

        //check if account exists
        if (!res->next()) {
            delete res;
            delete prep_stmt;
            delete con;
            return 1;
        } 
        else {

            //check if too many login attempts
            int loginAttempts = res->getInt("LoginAttempts");
            if (loginAttempts > 10) {
                delete res;
                delete prep_stmt;
                delete con;
                return 3;
            }

            //increment LoginAttempts
            prep_stmt = con->prepareStatement("UPDATE Accounts SET LoginAttempts = LoginAttempts + 1 WHERE UserName = ?");
            prep_stmt->setString(1, this->username);
            res = prep_stmt->executeQuery();

            //Get account Type and Network if name and password match
            prep_stmt = con->prepareStatement("SELECT Type, NetCategory FROM Accounts WHERE UserName = ? AND Password = ?");
            prep_stmt->setString(1, this->username);
            prep_stmt->setString(2, ReferenceValidationMechanism::EncryptString(this->password, 34));
            sql::ResultSet *res = prep_stmt->executeQuery();

            //check if wrong password
            if (!res->next()) {

                delete res;
                delete prep_stmt;
                delete con;
                return 2;
            } 
            else {

                std::string type = res->getString("Type");
                std::string network = res->getString("NetCategory");

                //check if connected to local network
                if(Network::GatewayMac().compare("error") == 0){

                    delete res;
                    delete prep_stmt;
                    delete con;
                    return -1;
                }
                //check if connected to correct local network
                else if(Network::GatewayMac().compare(network) != 0){

                    delete res;
                    delete prep_stmt;
                    delete con;
                    return 5;
                }

                //success \/\/\/

                //create account object for active account
                a = new Account(this->username, type, network);

                //set LoginAttempts to 0
                prep_stmt = con->prepareStatement("UPDATE Accounts SET LoginAttempts = 0 WHERE UserName = ?");
                prep_stmt->setString(1, this->username);
                res = prep_stmt->executeQuery();

                delete res;
                delete prep_stmt;
                delete con;
                return 0; //return success
            }
        }
    } 
	catch (sql::SQLException &e) {
        delete con; // Close the connection in case of an exception
        return -1;  // Return error code
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
