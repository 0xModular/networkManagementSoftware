/*
 * RemoteNetworkChangesLogEvent.h
 * Created on: Oct 26, 2023
 *
 * Author: Layne
 */

#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "Account.h"
#include "ReferenceValidationMechanism.h"
#include "DatabaseConnection.h"
#include <mysql_connection.h>
#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>

class ReferenceValidationMechanism;
class DatabaseConnection;
class Account;

class RemoteNetworkChangesLogEvent{

	public:

		//working
		bool RemoteNetworkChangesLogEvent::CreateNewEventLogInDB(std::string event, ReferenceValidationMechanism *r);
		RemoteNetworkChangesLogEvent(std::string event);

		//wip
		static std::vector<RemoteNetworkChangesLogEvent> ReadLogs(ReferenceValidationMechanism *r);
		~RemoteNetworkChangesLogEvent();

	private:

		std::string logEvent;

};



