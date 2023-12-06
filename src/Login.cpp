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
		this->errorCode = -1;
        return this->errorCode;
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
            this->errorCode = 1;
            return this->errorCode;
        } 
        else {

            //check if too many login attempts
            int loginAttempts = res->getInt("LoginAttempts");
            if (loginAttempts > 10) {
                delete res;
                delete prep_stmt;
                this->errorCode = 3;
                return this->errorCode;
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
                this->errorCode = 2;
                return this->errorCode;
            } 
            else {

                std::string type = res->getString("Type");
                std::string network = res->getString("NetCategory");

                //check if connected to local network
                if(Network::GatewayMac().compare("error") == 0){

                    delete res;
                    delete prep_stmt;
                    this->errorCode = -1;
                    return this->errorCode;
                }
                //check if connected to correct local network
                else if(Network::GatewayMac().compare(network) != 0){

                    delete res;
                    delete prep_stmt;
                    this->errorCode = 4;
                    return this->errorCode;
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
                this->errorCode = 0;
                return this->errorCode; //return success
            }
        }
    } 
	catch (sql::SQLException &e) {
        return -1;  // Return error code
    }
}
