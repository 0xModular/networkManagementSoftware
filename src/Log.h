/*
 * RemoteNetworkChangesLogEvent.h
 * Created on: Oct 26, 2023
 *
 * Author: Layne
 */

#pragma once
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <sstream>
#include "Account.h"
#include "ReferenceValidationMechanism.h"
#include "DatabaseConnection.h"
#include <mysql_connection.h>
#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>

class DatabaseConnection;
class ReferenceValidationMechanism; 
class Account;

class Log{

	public:

		//working
		static bool CreateNewEventLogInDB(std::string event, ReferenceValidationMechanism *r);
		static bool CreateNewEventLogInDB(std::string event, Account a);
		static bool CreateNewEventLogInDB(std::stringstream &eventss, ReferenceValidationMechanism *r);
		Log(std::string event);

		//wip
		static std::vector<Log> ReadLogs(ReferenceValidationMechanism *r);
		~Log();

	private:

		std::string logEvent;
		int time;
		Account *user;

};



