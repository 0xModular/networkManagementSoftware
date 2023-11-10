/*
 * DatabaseConnection.h
 * Created on Nov 11, 2023
 *
 * Author:
 */

#pragma once
#include <string>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

class DatabaseConnection{

	public:

    		static sql::Connection* GetSecureConnection(std::string sqlUsername, std::string sqlPassword);

};
