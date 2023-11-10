#include <string>
#include "DatabaseConnection.h"
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>


sql::Connection DatabaseConnection::getSecureConnection(std::string sqlUsername, std::string sqlPassword){

    const std::string server = "tcp://127.0.0.1:3306";

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
        	connection_properties["userName"] = sqlUsername;
        	connection_properties["password"] = sqlPassword;
        	connection_properties["OPT_SSL_KEY"] = ssl_key;
        	connection_properties["OPT_SSL_CERT"] = ssl_cert;
        	connection_properties["OPT_SSL_CA"] = ssl_ca;

        	// Establish an SSL/TLS encrypted connection
        	con = driver->connect(connection_properties);

            return con;

        }
        catch (sql::SQLException e) {
        
		return NULL;  // Exit the program or handle the error as needed.
    
	}

    	// Close the database connection when done.

}