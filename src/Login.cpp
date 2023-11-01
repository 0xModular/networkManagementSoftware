#ifndef SRC_LOGIN_I_
#define SRC_LOGIN_I_


#include "Login.h"


        //constructor
Login::Login(std::string name, std::string passphrase, std::string t){
            
	username = name;
	password = passphrase;
	type = t;
	loginAttempts = 0;

            
}

Login::~Login(){


}

void Login::encryptLoginInfo(){


}

void Login::sendLoginInfo(){
        
}


/*Account Login::waitforResponse(std::string *type, std::string *category){

	int responseCode = 0;
	std::string t = "Admin";
	std::string c = "Network1";
	type = &t;
	category = &c;
            //response code

	switch(responseCode){
    	case 0: return NULL; //change to return new account
    	case 1:  return NULL;
    	case 2:  return NULL;
    	}
	}
*/
#endif
