/*

#include <iostream>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>


const string server = "tcp://127.0.0.1:3306";
const string username = "your_username";
const string password = "your_password";

// Paths to SSL/TLS certificate and key files
const std::string ssl_key = "client-key.pem";
const std::string ssl_cert = "client-cert.pem";
const std::string ssl_ca = "server-ca.pem";

int connectDB() {
    sql::Driver* driver;
    sql::Connection* con;
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

        cout << "Connected to the MySQL server with SSL/TLS encryption!" << endl;

        // Now you can proceed with the login process.
        // You can create a prepared statement to check user credentials, for example.
        // ...

    } catch (sql::SQLException e) {
        cout << "Could not connect to the MySQL server. Error message: " << e.what() << endl;
        return 1;  // Exit the program or handle the error as needed.
    }

    // Close the database connection when done.
    delete con;
    return 0;
}
*/