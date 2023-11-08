#ifndef SRC_LOGIN_I_
#define SRC_LOGIN_I_

#include <iostream>
#include "Login.h"
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
class mysql_connection;

//constructor
Login::Login(std::string name, std::string passphrase){
            
	
	username = name;
	password = passphrase;
	loginAttempts = 0;
            
}

Login::~Login(){


}

Account* Login::generateEncryptedLoginConnection(){

const std::string server = "tcp://127.0.0.1:3306";
const std::string username = "your_username";
const std::string password = "your_password";

// Paths to SSL/TLS certificate and key files
const std::string ssl_key = "client-key.pem";
const std::string ssl_cert = "client-cert.pem";
const std::string ssl_ca = "server-ca.pem";


    sql::Driver* driver;
    sql::Connection *con;
    sql::PreparedStatement* pstmt;

    try {
        // Initialize the MySQL Connector/C++ driver
        driver = get_driver_instance();

        // Set SSL/TLS options
        sql::ConnectOptionsMap connection_properties;
        connection_properties["hostName"] = server;
        connection_properties["userName"] = username;
        connection_properties["password"] = password;
        connection_properties["OPT_SSL_KEY"] = ssl_key;
        connection_properties["OPT_SSL_CERT"] = ssl_cert;
        connection_properties["OPT_SSL_CA"] = ssl_ca;

        // Establish an SSL/TLS encrypted connection
        con = driver->connect(connection_properties);


        return sendInfoAndGetResponse(username, password, con);

    } catch (sql::SQLException e) {
        return NULL;  // Exit the program or handle the error as needed.
    }

    // Close the database connection when done.
    delete con;
}


// Assuming you have a valid database connection (con).
Account* Login::sendInfoAndGetResponse(std::string name, std::string pass, sql::Connection *con){


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

delete result;
delete pstmt;
Account *a = new Account(&name, new std::string("admin"), new std::string("1"));
return a;

}
#endif