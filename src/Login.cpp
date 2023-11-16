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


// Assuming you have a valid database connection (con).
int Login::SendInfoAndGetResponseStatus(Account *a){

	auto con = DatabaseConnection::GetSecureConnection("login", "login");

	if(con == nullptr)
		return -1;

 // Example: Retrieving 'column_name' from 'your_table_name' where 'id' = 1
    std::stringstream query;
	query << "SELECT UserName FROM Accounts WHERE UserName = " << this->username; // Change 'column_name', 'your_table_name', and 'id' as needed
    if (sql::mysql_query(con, query.str().c_str())) {
        sql::mysql_close(con);
        return 1;
    }

	std::stringstream query;
	query << "SELECT UserName FROM Accounts WHERE UserName = " << this->username << " AND Password = " << this->password; // Change 'column_name', 'your_table_name', and 'id' as needed
    if (sql::mysql_query(con, query.str().c_str())) {
        sql::mysql_close(con);
        return 2;
    }

    MYSQL_RES* result = mysql_store_result(cnn);
    if (result == nullptr) {
        std::cerr << "Error retrieving result: " << mysql_error(conn) << std::endl;
        mysql_close(con);
        return 1;
    }

    MYSQL_ROW row;
    if ((row = mysql_fetch_row(result))) {
        std::cout << "Value: " << row[0] << std::endl; // Access the value from the column
    } else {
        std::cout << "No data found" << std::endl;
    }

    mysql_free_result(result);
    mysql_close(con);
    return 0;
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