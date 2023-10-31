#ifndef SRC_LOGIN_I_
#define SRC_LOGIN_I_

#include "src/Login.h"
#include <string>


        //constructor
		Login::Login(std::string name, std::string passphrase, std::string t){
            
            this.userName = name;
            this.password = passphrase;
            this.type = t;
            this.loginAttempts = 0;

            
        }

		Login::~Login();

		Login::void encryptLoginInfo(){

            return;

            
        }

		Login::void sendLoginInfo(){
        
            return;
        }

		Login::Account waitforResponse(std::string *type, std::string *category){

            int resposeCode = 0
            std::string t = "Admin";
            std::string c = "Network1";
            Account a = Account.addAccount("Bob1998", type, category);
            *type = t*;
            *category = c*;
            //response code

            switch(responseCode){
                case 0: return a;
                case 1: /*error message wrong password*/ return null;
                case 2: /*error message account doesnt exist*/ return null;
            }
        }

#endif