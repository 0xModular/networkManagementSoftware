#ifndef SRC_LOGIN_I_
#define SRC_LOGIN_I_


#include "Login.h"


        //constructor
Login::Login(std::string name, std::string passphrase){
            
	
	username = name;
	password = passphrase;
	loginAttempts = 0;
            
}

Login::~Login(){


}

void Login::encryptLoginInfo(){


}

void Login::sendLoginInfo(){
        
}


Account* Login::waitForResponse(std::string *accType, std::string *cat){

	int responseCode = 0;
	std::string t = "Admin";
	std::string c = "Network1";
	accType = &t;
	cat = &c;
            //response code

	/*
	switch(responseCode){
    	case 0: return NULL; //change to return new account
    	case 1:  return NULL;
    	case 2:  return NULL;

	}
*/
	Account *a = new Account(&username, accType, cat);
	return a;
}

#endif