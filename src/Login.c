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

            encryptLoginInfo();
            sendLoginInfo();
            waitforResponse();
        }

		Login::~Login();

		Login::void encryptLoginInfo(){

            this.userName
            this.password

            
        }

		Login::void sendLoginInfo(){
        
            //send code

            waitforResponse()
        }

		Login::Account waitforResponse(){

            int resposeCode = 0
            Account a;
            //response code

            switch(responseCode){
                case 0: return a;
                case 1: /*error message wrong password*/ return null;
                case 2: /*error message account doesnt exist*/ return null;
            }
        }

#endif